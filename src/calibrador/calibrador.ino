/***********************************************************
 ** github: roninAd                                       **
 ***********************************************************
 * Reference page:                                        **
 * https://www.makerguides.com/servo-arduino-tutorial/    **
 ***********************************************************/
#include "ServoM.h"

   
int SERVOPIN = 9;
int BTNPIN = 4;

void setup() {


  Serial.begin(9600);

  pinMode(BTNPIN, INPUT_PULLUP);
  ServoM serv1 = ServoM(SERVOPIN);
}

void loop() {
  //   serv1.start(0); 
  int state = digitalRead(BTNPIN);

  
  delay(1000);
}
