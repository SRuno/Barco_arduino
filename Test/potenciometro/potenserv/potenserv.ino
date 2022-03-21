#include <Servo.h>

Servo myservo;  // crea el objeto servo

int pos = 0;    // posicion del servo

void setup() {
   myservo.attach(3);  // vincula el servo al pin digital 9
}

void loop() {
  pos = map(analogRead(A1), 0, 750, 0, 180);
   myservo.write(pos);              
   delay(30); 
}
