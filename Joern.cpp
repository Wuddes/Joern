#include "Arduino.h"
#include "Joern.h"
#include <Servo.h>

int errorFlag = 0;
Joern::Joern(){
/*********************************************
                  Pins
*********************************************/  
  _pinServoAugen = 52;
  _pinServoOhren = 50;
  _pinServoSchwenken = 48;
  _pinServoKippen = 46;
  _pinLDR = A0; //Light Dependant Resistor 
  _pinPIR = 44; //Pyroelectric InfraRed Sensor
  _pinButton = 42;
  _pinDispCLK = 8;
  _pinDispDI = 9;
  _pinDispCS = 10;
/*********************************************
               Servopositionen
*********************************************/
  _augenAuf = 30;
  _augenZu = 90;
  _ohrenRunter = 130;
  _ohrenRauf = 90;
  _linksDrehen = 110;
  _rechtsDrehen = 70;
  _vorneKippen = 70;
  _hintenKippen = 110;
  _gerade = 90;
  _aufrecht = 90;
}
/***
Funktion: init
Parameter: 

Resultat: 
  Initialisiere Komponenten.
***/
void Joern::init(){
    _augen.attach(_pinServoAugen);
    _ohren.attach(_pinServoOhren);
    _schwenken.attach(_pinServoSchwenken);
    _kippen.attach(_pinServoKippen);
  }

/***
Funktion: _singleMotion
Parameter: 
  Servo servo:  angesteuerter Servomotor
  int pos:      gewünschte Position
  int spe:      Bewegungsgeschwindigkeit

Resultat: 
  Bewegung in eine Richtung.
***/
void Joern::_singleMotion(Servo servo, int pos, int spe){
  int currServoPos = servo.read(); // current angle of the servo 
  if(currServoPos <= pos){
    for (currServoPos; currServoPos <= pos; currServoPos += spe){
      servo.write(currServoPos);
      delay(20);
    }
  } else {
    for (currServoPos; currServoPos >= pos; currServoPos -= spe){
      servo.write(currServoPos);
      delay(20);
     }
  }
}

void Joern::bewegeOhren(int pos, int spe){
if ((pos < _ohrenRauf) || (pos > _ohrenRunter)){
  if(errorFlag == 0){
    Serial.println("Ungueltige Werteangabe: bewegeOhr");
    Serial.println("Werte zwischen " + String(_ohrenRauf) + " und " + String(_ohrenRunter) + " werden erwartet!");
    errorFlag +=1;
  }
  }else{
    _singleMotion(_ohren,pos,spe);
  }
}
  

