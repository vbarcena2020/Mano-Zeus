#include "ServoM.h"

enum
{
  SERVOPIN = 7,
  BTNPIN = 2,
  READINGS = 1,

  FORWARD = 1,
  BACKWARD = 0,

  MAX = 3000,
  MIN = 300,
};


ServoM servo;



void setup() {
  Serial.begin(9600);
  servo.attach(SERVOPIN);
  

  pinMode(BTNPIN, INPUT_PULLUP);  
}

void print_result(int value, int result)
{
    Serial.print("Value: ");
    Serial.print(value + 1);
    Serial.print(";   Reuslt: ");
    Serial.println(result);
}

int calibrate(int mode)
{
  int value = 0;
  int total = 0;
  
  while (value != READINGS)
  {
  
   
  bool push = false;
  int time1 = 0;
  int time2 = millis();

  /* While the botton is pressed */
  while (!digitalRead(BTNPIN)){
  
      if (mode == FORWARD) { servo.Forward(); }
      if (mode == BACKWARD) { servo.Backward(); } 
    
    push = true;
    time1 = millis();
  }
  servo.Stop();

  /* The button is not pressed */
 
  // We add the new time value if the button was pressed
  if (push){
    int result = time1 - time2;
    print_result(value, result);

    // Store the time if the value is correct
  if (result >= MIN && result <= MAX){
    total+= result;
    value++;
  }

    push = false;   
  }  
  delay(10);
  }
  return (total/value);
}
 

void loop() {
  for (int i = 0; i <= FORWARD + BACKWARD; i++){
    int mid_time;
    mid_time = calibrate(i);
    
    if (i == FORWARD){ Serial.println("Forward: "); }
    if (i == BACKWARD){ Serial.println("BACKWARD: "); }

    Serial.print("\nMid time = ");
    Serial.println(mid_time);
  }

  while(1);
}
