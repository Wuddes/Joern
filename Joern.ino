#include "Joern.h"
#include <Servo.h>


Joern robo;
void setup() {
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Programm startet");
  robo.init();
}

void loop() {
 robo.sweepDrehe(1);
 delay(1000);   
 robo.sweepKippe(1);
 delay(1000);     
 robo.sweepAugen(3);
 delay(1000);      
  robo.sweepOhren(2);
 delay(1000);                 
}

