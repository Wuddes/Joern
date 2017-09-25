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
 robo.bewegeOhren(90,1);
 delay(1000);
 robo.bewegeOhren(130,1);
 delay(1000);                        
}

