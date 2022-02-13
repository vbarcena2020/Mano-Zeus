#include <Servo.h>

#include "ServoM.h"
#include "Arduino.h"

enum
{
  FORWARD = 0,
  BACKWARD = 1,
};

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
  int mode = FORWARD;

  /* Limit */
  if (pos + grades > 180){ grades = 180 - pos;}
  

  if (grades < 0) {
    if (pos - grades < 0) {grades = 0 + pos;}
    mode = BACKWARD ; 
    grades *= -1;
    }  
  if (grades == 0){ Stop();}

  if (mode == FORWARD && grades != 0){
    Forward();

    float tim = (grades*10/180)*TIMEFORW / 100;
    delay(tim);
  }

  if (mode == BACKWARD && grades != 0){
    Backward();
    Serial.println(grades);
    double tim = (grades/180)*TIMEBACK;
    delay(tim);
  }
  
  
  Stop();
}


bool ServoM::measure_mode(){
  // Que localize los grados máximos y los minimos y empize el calibrado
  // Hacer calibrado en otro punto h
  Serial.println("1");
  delay(1000);
  return calibrated;
  }
