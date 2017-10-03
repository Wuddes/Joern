 #include "Joern.h"
#include "Commands.h"
#include <Servo.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SharpMem.h>

/*********************************************
          Displaysteuerungsparameter
*********************************************/  
Adafruit_SharpMem display(SHARP_SCK, SHARP_MOSI, SHARP_SS, 144, 168);
int minorHalfSize; // 1/2 of lesser of display width or height
/*********************************************/  

Joern robo; //Roboter definieren
boolean disEn;
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  robo.init(); //Roboter initialisieren
  display.begin();
  display.clearDisplay();
  minorHalfSize = min(display.width(), display.height()) / 2;
}

void loop() {
/*********************************************
          Displayeinstellungen
*********************************************/  
 display.setTextSize(4); //Textgrösse
 display.setRotation(0); //Textrotation
 display.setTextColor(BLACK);
 display.setCursor(1,1); //Startpunkt für Text festlegen
/*********************************************/  
/*********************************************
          Displayverwendung
          Verwende Display:       TRUE
          Verwende Display nicht: FALSE
*********************************************/  
disEn = true; //Display Enable
/*********************************************/  

char inCom; //Gelesener Char von der Serial1-Kommunikation
if (Serial1.available() > 0) {  //Kommunikation liegt am Serial1 an
  inCom = Serial1.read(); //Lese den anliegenden Char
  
  switch (inCom){
    case COM1:
      robo.sweepAugen(3);
      if(disEn){
         display.clearDisplay();
         display.println("Augen");
         display.refresh();
        }
      break;
    case COM2:
      robo.sweepOhren(3);
      if(disEn){
        display.clearDisplay();
        display.println("Ohren");
        display.refresh(); 
      }
      break;
    case COM3:
      robo.sweepKippe(1);
      if(disEn){
        display.clearDisplay();
        display.println("Kippen");
        display.refresh();
      }
      break;
    case COM4:
      robo.sweepDrehe(1);
      if(disEn){
        display.clearDisplay();
        display.println("Schwenken");
        display.refresh();
      }
      break;
  }  
  delay(500);
}
              
}

