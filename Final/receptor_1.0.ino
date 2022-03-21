#include <Arduino.h>
// Receptor Radio
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
const uint64_t pipeIn = 0xE8E7F0F0E1LL;
RF24 radio(9, 10);
struct Received_data {
  byte ch1;
};
int ch1_value = 0;
Received_data received_data;

// Servo
#include<Servo.h>
Servo myservo;

// Motores

const int ENA = 2;
const int IN1 = 3;
const int IN2 = 4;
const int IN3 = 5;
const int IN4 = 6;
const int ENB = 7;

const int motorA[3] = { ENA, IN1, IN2};
const int motorB[3] = { ENB, IN3, IN4};

int velocidad = 0;
int giro = 90;

void setup()
{
  // Radio Setup
  pinMode(1, OUTPUT);
  Serial.begin(9600);
  received_data.ch1 = 127;
  radio.begin();
  radio.setAutoAck(false);
  radio .setDataRate(RF24_250KBPS);
  radio.openReadingPipe(1,pipeIn);
  radio.startListening();

  // Pines de motores
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Servo
  myservo.attach(8);
}

unsigned long last_Time = 0;

void receive_the_data()
{
  while ( radio.available() )
  {
  radio.read(&received_data, sizeof(Received_data));
  last_Time = millis();
  }
}

void moveForward(const int motor[3], int velocidad)
{

}

void loop()
{
  receive_the_data();
  Serial.println(received_data.ch1);
  switch (received_data.ch1)
  {
  case 0:
    velocidad = 0;
    break;
  case 10:
    velocidad = 10;
    break;
  case 20:
    velocidad = 20;
    break;
  case 30:
    velocidad = 30;
    break;
  case 40:
    velocidad = 40;
    break;
  case 50:
    velocidad = 50;
    break;
  case 60:
    velocidad = 60;
    break;
  case 70:
    velocidad = 70;
    break;
  case 80:
    velocidad = 80;
    break;
  case 90:
    velocidad = 90;
    break;
  case 100:
    velocidad = 100;
    break;
  case 110:
    velocidad = 130;
    break;
  case 120:
    velocidad = 200;
    break;
  case 1:
    giro = 48;
    break;
  case 2:
    giro = 55;
    break;
  case 3:
    giro = 62;
    break;
  case 4:
    giro = 69;
    break;
  case 5:
    giro = 76;
    break;
  case 6:
    giro = 83;
    break;
  case 7:
    giro = 90;
    break;
  case 8:
    giro = 97;
    break;
  case 9:
    giro = 104;
    break;
  case 11:
    giro = 111;
    break;
  case 12:
    giro = 118;
    break;
  case 13:
    giro = 125;
    break;
  case 14:
    giro = 132;
    break;
  default:
    break;
  }
  myservo.write(giro);
  digitalWrite(motorA[1], HIGH);
  digitalWrite(motorA[2], LOW);
  analogWrite(motorA[0], velocidad);
  digitalWrite(motorB[1], HIGH);
  digitalWrite(motorB[2], LOW);
  analogWrite(motorB[0], velocidad);
}
