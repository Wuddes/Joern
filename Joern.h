#ifndef Joern_h
#define Joern_h
#include "Arduino.h"
#include <Servo.h>
/*********************************************
               Displaypins
*********************************************/ 
#define SHARP_SCK  13
#define SHARP_MOSI 11
#define SHARP_SS   10
#define BLACK 0
#define WHITE 1


class Joern{
  private:
/*********************************************
                  Pins
*********************************************/  
  int _pinServoAugen;
  int _pinServoOhren;
  int _pinServoSchwenken;
  int _pinServoKippen;
  int _pinLDR; //Light Dependant Resistor 
  int _pinPIR; //Pyroelectric InfraRed Sensor
  int _pinButton;
  int _pinDispCLK;
  int _pinDispDI;
  int _pinDispCS;
  uint8_t _SHARP_SCK;
  uint8_t _SHARP_MOSI;
  uint8_t _SHARP_SS;
/*********************************************
               Servopositionen
*********************************************/  
  int _augenAuf;
  int _augenZu;
  int _ohrenRunter;
  int _ohrenRauf;
  int _linksDrehen;
  int _gerade;
  int _rechtsDrehen;
  int _vorneKippen;
  int _aufrecht;
  int _hintenKippen;
/*********************************************
               Servomotoren
*********************************************/  
  Servo _ohren;
  Servo _augen;
  Servo _schwenken;
  Servo _kippen;

/*********************************************
              Private Funktionen
*********************************************/ 
  void _singleMotion(Servo servo, int pos, int spe); //Bewegung in eine Richtung

  public:
  Joern(); //Konstruktor
  void init(); //Motorinitialisierung
  void bewegeOhren(int pos, int spe);
  void bewegeAugen(int pos, int spe);
  void drehe(int pos, int spe);
  void kippe(int pos, int spe);
  void sweepOhren(int spe);
  void sweepAugen(int spe);
  void sweepDrehe(int spe);
  void sweepKippe(int spe);
  };
  #endif
