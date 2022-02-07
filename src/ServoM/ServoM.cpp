

#include "ServoM.h"
#include "Arduino.h"

ServoM::ServoM(int pin){ // Construct
  PIN = pin;
  pinMode(pin, OUTPUT);
}

void ServoM::set_speed(int gear){

  GEAR = gear;
  
  if (gear > MAX_GEAR){ gear = MAX_GEAR; }
  if (gear < -MAX_GEAR) { gear = -MAX_GEAR; }
  
  if (gear > 0 ) { Speed = gear + MIN1; }
  else { Speed = gear + MIN2; }

  if (gear == 0){Speed = 0;}

  tim = TG5;
}


// Starts the servo
void ServoM::start(int gear){
  set_speed(gear);
  
  analogWrite(PIN, Speed);
  delay(20);
}


// Turns de servo the selected grades
void ServoM::turn(int grades, int gear){

  // If the grades exceeds 180 grades, it stays in 180º
  if (pos + grades > 180){ grades = 180 - pos;}
  if (pos - grades < -180) {grades = -180 + pos;}

  if (grades != 0){ start(gear);}
  
  delay(180/(grades*tim));
  start(0);
}



void ServoM::turn(int grades){ turn(grades, 5); }

bool ServoM::measure_mode(){
  // Que localize los grados máximos y los minimos y empize el calibrado
  // Hacer calibrado en otro punto h
  Serial.println("1");
  delay(1000);
  return calibrated;
  }
