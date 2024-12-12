Projeto de Fechadura Eletrônica com Arduino

Este projeto utiliza um Arduino para criar uma fechadura eletrônica que combina segurança e tecnologia. 
O sistema é controlado por uma senha e utiliza componentes como display LCD, servo motor, LEDs, sensores ultrassônicos e botões de entrada.

Funcionamento:
Sensor Ultrassônico: Detecta a presença de uma pessoa a menos de 10 cm da fechadura e ativa o sistema.
Interface de Entrada: O usuário digita uma senha de 3 dígitos usando botões.

Validação da Senha:
Se correta, o sistema:
Exibe "Senha Correta!" no LCD.
Aciona o servo motor, que gira 90° para destrancar a fechadura.
Troca o LED indicador de vermelho (travado) para verde (destravado).
Se incorreta, exibe "Senha Incorreta!" e reinicia o processo.

Feedback Visual:
LCD para exibir mensagens ao usuário.
LEDs para indicar o estado da fechadura (verde = destravado, vermelho = travado).

Componentes Principais:
Arduino UNO (ou equivalente): Gerencia o sistema.
Servo Motor: Controla a abertura física da fechadura.
Sensor Ultrassônico (HC-SR04): Detecta proximidade.
Display LCD com módulo I2C: Exibe mensagens.
Botões: Permitem entrada da senha.
LEDs: Indicadores visuais do estado da fechadura.

Este projeto é ideal para aplicações residenciais ou didáticas, demonstrando conceitos de segurança digital, eletrônica e programação com Arduino.
