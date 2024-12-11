#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo1;

int pos = 0;
const int TrigPino = 5;
const int EcoPino = 6;
float distancia = 0;
float duracao;
int led1 = 9;
int led2 = 10;
const int TAMANHOSENHA = 3;
String senhaDigitada = "";
String senha = "123";
const int botao1 = 4;
const int botao2 = 3;
const int botao3 = 2;
const int enter = 1;

void setup() {
  Serial.begin(9600);
  pinMode(TrigPino, OUTPUT);
  pinMode(EcoPino, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(botao1, INPUT_PULLUP); 
  pinMode(botao2, INPUT_PULLUP);
  pinMode(botao3, INPUT_PULLUP);
  pinMode(enter, INPUT_PULLUP);
  
  lcd.init();
  lcd.backlight();
  servo1.attach(11);
  servo1.write(0);
}

void loop() {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);

  digitalWrite(TrigPino, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPino, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPino, LOW);

  duracao = pulseIn(EcoPino, HIGH);
  distancia = (duracao * 0.0343) / 2;

  if (distancia < 10) {
    lcd.setCursor(0, 0);
    lcd.print("SEJA BEM VINDO");
    lcd.setCursor(0, 1);
    lcd.print("DIGITE A SENHA: ");

    if (digitalRead(botao1) == LOW) {
      if (senhaDigitada.length() < TAMANHOSENHA) {
        senhaDigitada += "1";
      }
      delay(300);
    }
    if (digitalRead(botao2) == LOW) {
      if (senhaDigitada.length() < TAMANHOSENHA) {
        senhaDigitada += "2";
      }
      delay(300);
    }
    if (digitalRead(botao3) == LOW) {
      if (senhaDigitada.length() < TAMANHOSENHA) {
        senhaDigitada += "3";
      }
      delay(300);
    }

    if (senhaDigitada.length() == TAMANHOSENHA && digitalRead(enter) == LOW) {
      lcd.clear();
      if (senhaDigitada == senha) {
        digitalWrite(led1, LOW);
        digitalWrite(led2, HIGH);
        lcd.setCursor(0, 0);
        lcd.print("SENHA CORRETA!");

        for (pos = 0; pos <= 90; pos++) {
          servo1.write(pos);
          delay(15);
        }
      } else {
        lcd.setCursor(0, 0);
        lcd.print("SENHA INCORRETA!");
        delay(2000);
        lcd.clear();
      }
      delay(2000);
      senhaDigitada = "";
    }
  }
}