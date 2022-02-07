#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);
  myservo.attach(6);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  int in = 2;
  int tim = 100;
    // in steps of 1 degree
    // 102
    for (int i = 80 ; i <= 180 ; i += 1){
      Serial.println(i);
      myservo.write(i);
      delay(2000);
    }
  
  

  myservo.detach();
  while(1);
  
}
