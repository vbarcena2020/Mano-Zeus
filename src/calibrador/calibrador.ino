/***********************************************************
 ** github: roninAd                                       **
 ***********************************************************
 * Reference page:                                        **
 * https://www.makerguides.com/servo-arduino-tutorial/    **
 ***********************************************************/
#include "ServoM.h"

   
int SERVOPIN = 9;
int BTNPIN = 7;
ServoM serv1 = ServoM(SERVOPIN);
int vel = 4;

void setup() {


  Serial.begin(9600);

  pinMode(BTNPIN, INPUT_PULLUP);
}

void loop() {
  
  serv1.start(5);
  delay(580);
  serv1.start(0);
  delay(2000);
  serv1.start(-5);
  delay(530);
  serv1.start(0);
  delay(2000);
}
