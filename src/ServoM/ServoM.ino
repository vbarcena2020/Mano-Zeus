#include "./ServoM.h"
#include <Servo.h>


#define PINSERVO1  6  
#define PINSERVO2  7
#define PINSERVO3  8


ServoM servo1;


void setup() {
  Serial.begin(9600);
  servo1.attach(PINSERVO3);
}

void loop() {
  servo1.turn(180);
  while(true);
}
