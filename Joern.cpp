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
  _augenAuf = 20;
  _augenZu = 90;
  _ohrenRunter = 130;
  _ohrenRauf = 90;
  _linksDrehen = 110;
  _rechtsDrehen = 70;
  _vorneKippen = 85;
  _hintenKippen = 95;
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
/***
Funktion: bewegeOhren
Parameter: 
  int pos:      gewünschte Position
  int spe:      Bewegungsgeschwindigkeit

Resultat: 
  Richtet Ohren aus
***/
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
/***
Funktion: bewegeAugen
Parameter: 
  int pos:      gewünschte Position
  int spe:      Bewegungsgeschwindigkeit

Resultat: 
  Richtet Augen aus
***/
void Joern::bewegeAugen(int pos, int spe){
  if ((pos < _augenAuf) || (pos > _augenZu)){
    if(errorFlag == 0){
      Serial.println("Ungueltige Werteangabe: bewegeAugen");
      Serial.println("Werte zwischen " + String(_augenAuf) + " und " + String(_augenZu) + " werden erwartet!");
      errorFlag +=1;
    }
  }else{
    _singleMotion(_augen,pos,spe);
  }
}
/***
Funktion: drehe
Parameter: 
  int pos:      gewünschte Position
  int spe:      Bewegungsgeschwindigkeit

Resultat: 
  Rotation um Z-Achse
***/
void Joern::drehe(int pos, int spe){
  if ((pos < _rechtsDrehen) || (pos > _linksDrehen)){
    if(errorFlag == 0){
      Serial.println("Ungueltige Werteangabe: drehe");
      Serial.println("Werte zwischen " + String(_rechtsDrehen) + " und " + String(_linksDrehen) + " werden erwartet!");
      errorFlag +=1;
    }
  }else{
    _singleMotion(_schwenken,pos,spe);
  }    
}
/***
Funktion: kippe
Parameter: 
  int pos:      gewünschte Position
  int spe:      Bewegungsgeschwindigkeit

Resultat: 
  Rotation um Y-Achse
***/
void Joern::kippe(int pos, int spe){
  if ((pos < _vorneKippen) || (pos > _hintenKippen)){
    if(errorFlag == 0){
      Serial.println("Ungueltige Werteangabe: kippe");
      Serial.println("Werte zwischen " + String(_vorneKippen) + " und " + String(_hintenKippen) + " werden erwartet!");
      errorFlag +=1;
    }
  }else{
    _singleMotion(_kippen,pos,spe);
  } 
}

void Joern::sweepOhren(int spe){
  bewegeOhren(_ohrenRunter,spe);
  bewegeOhren(_ohrenRauf,spe);
  bewegeOhren(100,spe);
}
void Joern::sweepAugen(int spe){
  bewegeAugen(_augenAuf,spe);
  delay(1000);
  bewegeAugen(_augenZu,spe);
}
void Joern::sweepDrehe(int spe){
  drehe(_rechtsDrehen,spe);
  drehe(_linksDrehen,spe);
  drehe(_gerade,spe);
}
void Joern::sweepKippe(int spe){
  kippe(_vorneKippen,spe);
  kippe(_hintenKippen,spe);
  kippe(_aufrecht,spe);
}
  

