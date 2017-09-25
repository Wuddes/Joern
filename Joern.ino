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
  robo.sweep();
}

