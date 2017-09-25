#include "Arduino.h"
#include "Joern.h"
#include <Servo.h>


Joern::Joern(){
  _pinServoAugen = 9;
}

void Joern::init(){
    _augen.attach(9);
  }

void Joern::sweep(){
  int pos=0;
for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    _augen.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    _augen.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  }
  

