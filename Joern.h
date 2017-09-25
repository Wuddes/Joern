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
               Servomotoren
*********************************************/  
  Servo _ohren;
  Servo _augen;
  Servo _schwenken;
  Servo _kippen;
/*********************************************
                  Display
*********************************************/  

  
  public:
  Joern(); //Konstruktor
  void init(); //Motorinitialisation
  void sweep(); //ServoDemo

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
