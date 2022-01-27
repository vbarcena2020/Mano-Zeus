/***********************************************************
 ** github: roninAd                                       **
 ***********************************************************
 * Reference page:                                        **
 * https://www.makerguides.com/servo-arduino-tutorial/    **
 ***********************************************************/
 #include "ServoM.h"


void setup() {
   
  int servoPin = 9;
  
  ServoM serv1 = ServoM(servoPin);
}

void loop() {
  serv1.start(0);
}
