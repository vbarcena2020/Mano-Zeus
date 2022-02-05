

#include "ServoM.h"
#include "Arduino.h"

ServoM::ServoM(int pin){ // Construct
  PIN = pin;
  pinMode(pin, OUTPUT);
}

void ServoM::set_speed(int gear){
  
  if (gear > GEAR){ gear = GEAR; }
  if (gear < -GEAR) { gear = -GEAR; }
  
  if (gear > 0 ) { Speed = gear + MIN1; }
  else { Speed = gear + MIN2; }

  if (gear == 0){Speed = 440;}
}


// Starts the servo
void ServoM::start(int gear){
  set_speed(gear);
  
  analogWrite(PIN, Speed);
  delay(10);
}
