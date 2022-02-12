#include "ServoM.h"
#include <Servo.h>


#define PINSERVO1  6  
#define PINSERVO2  7
#define PINSERVO3  8


ServoM servo1;
Servo servo2;

void setup() {
  Serial.begin(9600);
  servo1.attach(PINSERVO1);
}

void loop() {
   servo1.Backward();
   delay(2000);

   servo1.Stop();
   delay(2000);
   
   servo1.Forward();
   delay(2000);
    
   servo1.Stop();
   delay(2000); 
}
