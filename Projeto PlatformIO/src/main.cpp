#include <Arduino.h>



/*-------------Funções do PWM---------------*/
/*
1)- ledcAttachPin(pin,ch);      //  Associa certo pino a certo canal PWM. São 16 canais possíveis ao todo
2)- ledcSetup(ch, frequencia (Hz), resolução (número de bits));   // Define a frequência e resolução de certo canal
A frequência máxima e a resolução usada se relacionam pela seguinte equação:

                            Clock (80Mhz)
Frequência Máxima(Hz) = ---------------------
                         Resolução(2^(n_bits))


3)- ledcWrite(ch, duty cycle(binário));                           // Altera o Duty cicle do canal.
*/

/*-----------Funções do ADC-----------------*/
/* O ADC do ESP32 tem 12 bits, o que significa que ele retorna um número
com resolução 2^12 = 4096.

Não é necessário declarar o pino como entrada, basta usar a função
analogRead(Pin); e essa função retorna um valor de 0 a 4095.
0 para 0 Volts e 4095 para 3.3 Volts.
*/

/*---------Mapeamento de Hardware-----------*/
#define dc_motor        21
#define potenciometro    4
#define led              5



/*---------Configurações Iniciais-----------*/
void setup() {
  ledcAttachPin(dc_motor,0);
  ledcAttachPin(led,0);
  ledcSetup(0,312500, 8);
}
/*------------Loop nfinito------------------*/
void loop() {
  //na função map estamos mapeando o valor de 0 a 4095 do ADC
  //com o valor de 0 a 255 do PWM. Armazenamos o resultado na
  //variável mapa. E então a usamos para controlar o motor DC
  unsigned mapa = map(analogRead(potenciometro),
                  0, 4095,
                  0 , 255);
  ledcWrite(0, mapa);
}