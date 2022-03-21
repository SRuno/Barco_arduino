/*  Prueba distancia NRF24L01 programa del Transmisor
    NRF24 // Arduino UNO,NANO 
    GND    ->   GND
    Vcc    ->   3.3V Fuente Externa
    CE     ->   D9
    CSN    ->   D10
    CLK    ->   D13
    MOSI   ->   D11
    MISO   ->   D12
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>                       // debe descargar la libreria RF24.h
const uint64_t codigo= 0xE8E7F0F0E1LL; //Mismo codigo en el RX y TX
RF24 radio(9, 10);                      // asigna pines para CSN y CE
struct dato_a_enviar {
  byte ch1; 
};
dato_a_enviar sent_data;
void setup()
{ 
  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);  // configura 250KBPS
  radio.openWritingPipe(codigo);  
  sent_data.ch1 = 127;              // canal 127
}
void loop()
{
  sent_data.ch1 = 255;             
  radio.write(&sent_data, sizeof(dato_a_enviar));    // envia 8 bits en "1" 
  sent_data.ch1 = 0;
  radio.write(&sent_data, sizeof(dato_a_enviar));    // envia 8 bits en "0" 
}
