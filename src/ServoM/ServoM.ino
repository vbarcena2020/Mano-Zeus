#include "ServoM.h"

   
int SERVOPIN = 6;

ServoM serv1 = ServoM(SERVOPIN);

// Change global variable
int value = 0;
int total = 0;

void setup() {
  Serial.begin(9600);  
}

void loop() {
  // Initial values of each variable
  int vel = 5;
  serv1.turn(60);
  while(! serv1.measure_mode());

}
