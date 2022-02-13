#include <Servo.h>

#include "ServoM.h"
#include "Arduino.h"

void ServoM::Forward()
{
  for (int i = LEFT ; i >= LEFT - STEP ; i--) {
    this->write(i);
    delay(TACEL);
    }
}

void ServoM::Backward()
{
  for (int i = RIGHT ; i <= RIGHT + STEP ; i++) {
    this->write(i);
    delay(TACEL);
    }
}


void ServoM::Stop(){ this->write(STOP); }


void ServoM::turn(int grades){

  // If the grades exceeds 180 grades, it stays in 180º
  if (pos + grades > 180){ grades = 180 - pos;}
  if (pos - grades < -180) {grades = -180 + pos;}

  if (grades != 0){ Stop();}
  
  delay(180/(grades*TIMEHALF));
  Stop();
}


bool ServoM::measure_mode(){
  // Que localize los grados máximos y los minimos y empize el calibrado
  // Hacer calibrado en otro punto h
  Serial.println("1");
  delay(1000);
  return calibrated;
  }
