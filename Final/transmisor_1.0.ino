// Emisor radio
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
const uint64_t codigo= 0xE8E7F0F0E1LL;
RF24 radio(9, 10);
struct dato_a_enviar {
  byte ch1;
};
dato_a_enviar sent_data;

// LCD
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2);

// Potenciometro
const int poten_vel = A2;
const int poten_dir = A3;

// Variable for
int i1 = 0;
int i2 = 0;

void setup()
{
  // Radio Setup
  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.openWritingPipe(codigo);
  sent_data.ch1 = 127;

  // LCD Setup
  lcd.init();
  lcd.backlight();
  lcd.setCursor(4,0);
  lcd.print("MSV Nami");
  lcd.setCursor(3,1);
  lcd.print("Iniciando");
  delay(1000);
  lcd.clear();
}
void loop()
{
  // Recopilar información
  int vel_val = analogRead(poten_vel);
  int dir_val = analogRead(poten_dir);

  // Tratamiento de las variables
  int num1 = vel_val / 50;
  int num2 = dir_val / 50;

  // Escritura en LCD y envio de paquetes de Velocidad
  lcd.setCursor(0,0);
  lcd.print("V[");
  switch (num1)
  {
  case 0:
    lcd.print("#------------]");
    sent_data.ch1 = 0;
    break;
  case 1:
    lcd.print("##-----------]");
    sent_data.ch1 = 10;
    break;
  case 2:
    lcd.print("###----------]");
    sent_data.ch1 = 20;
    break;
  case 3:
    lcd.print("####---------]");
    sent_data.ch1 = 30;
    break;
  case 4:
    lcd.print("#####--------]");
    sent_data.ch1 = 40;
    break;
  case 5:
    lcd.print("######-------]");
    sent_data.ch1 = 50;
    break;
  case 6:
    lcd.print("#######------]");
    sent_data.ch1 = 60;
    break;
  case 7:
    lcd.print("########-----]");
    sent_data.ch1 = 70;
    break;
  case 8:
    lcd.print("#########----]");
    sent_data.ch1 = 80;
    break;
  case 9:
    lcd.print("##########---]");
    sent_data.ch1 = 90;
    break;
  case 10:
    lcd.print("###########--]");
    sent_data.ch1 = 100;
    break;
  case 11:
    lcd.print("############-]");
    sent_data.ch1 = 110;
    break;
  case 12:
    lcd.print("#############]");
    sent_data.ch1 = 120;
    break;
  default:
    break;
  }
  radio.write(&sent_data, sizeof(dato_a_enviar));

  // Escritura en LCD y envio de paquetes referente a Dirección
  lcd.setCursor(0,1);
  lcd.print("D[");
  switch (num2)
  {
  case 0:
    lcd.print("#######------]");
    sent_data.ch1 = 1;
    break;
  case 1:
    lcd.print("-######------]");
    sent_data.ch1 = 2;
    break;
  case 2:
    lcd.print("--#####------]");
    sent_data.ch1 = 3;
    break;
  case 3:
    lcd.print("---####------]");
    sent_data.ch1 = 4;
    break;
  case 4:
    lcd.print("----###------]");
    sent_data.ch1 = 5;
    break;
  case 5:
    lcd.print("-----##------]");
    sent_data.ch1 = 6;
    break;
  case 6:
    lcd.print("------#------]");
    sent_data.ch1 = 7;
    break;
  case 7:
    lcd.print("------##-----]");
    sent_data.ch1 = 8;
    break;
  case 8:
    lcd.print("------###----]");
    sent_data.ch1 = 9;
    break;
  case 9:
    lcd.print("------####---]");
    sent_data.ch1 = 11;
    break;
  case 10:
    lcd.print("------#####--]");
    sent_data.ch1 = 12;
    break;
  case 11:
    lcd.print("------######-]");
    sent_data.ch1 = 13;
    break;
  case 12:
    lcd.print("------#######]");
    sent_data.ch1 = 14;
    break;
  default:
    break;
  }
  radio.write(&sent_data, sizeof(dato_a_enviar));
}
