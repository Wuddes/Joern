#ifndef Joern_h
#define Joern_h
#include "Arduino.h"
#include <Servo.h>

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
/*********************************************
                  Display
*********************************************/  

  
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

/*********************************************
              Getter/Setter
*********************************************/  
  int get_pinServoAugen();
  void set_pinServoAugen();
  int get_pinServoOhren();
  void set_pinServoOhren();
  int get_pinServoSchwenken();
  void set_pinServoSchwenken();
  int get_pinServoKippen();
  void set_pinServoKippen();
  int get_pinLDR();
  void set_pinLDR();
  int get_pinPIR();
  void set_pinPIR();
  int get_pinButton();
  void set_pinButton();
  int get_pinDispCLK();
  void set_pinDispCLK();
  int get_pinDispDI();
  void set_pinDispDI();
  int get_pinDispCS();
  void set_pinDispCS();
/*********************************************

*********************************************/  

  };
  #endif
