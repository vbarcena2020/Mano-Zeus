
#include "ServoM.h"
#include "Arduino.h"

/* States of turn */ 
enum
{
  FORWARD = 0,
  BACKWARD = 1,
};


void ServoM::Forward()
{
  for (int i = LEFT_ ; i >= LEFT_ - STEP_ ; i--) {
    this->write(i);
    delay(TACEL_);
    }
}


void ServoM::Backward()
{
  for (int i = RIGHT_ ; i <= RIGHT_ + STEP_ ; i++) {
    this->write(i);
    delay(TACEL_);
    }
}


void ServoM::Stop(){ this->write(STOP_); }

double ServoM::check_grades(double grades)
{
   /* Limit forward*/
   if (pos_ + grades > max_pos_){ grades = max_pos_ - pos_; }
  

   if (grades < 0) {
    /* Limit backward and changes mode */
    if ((pos_ + grades) < min_pos_) { grades = min_pos_- pos_; }  
    }  

    return grades;
}

void ServoM::turn(double grades){
  int mode = FORWARD;
  double tim;

  grades = check_grades(grades);

  if (grades < 0){ mode = BACKWARD ; grades *= -1; }
  if (grades == 0){ Stop();}

  /* Moves the servo forward */
  if (mode == FORWARD && grades != 0){
    Forward();

    tim = (grades/180)*TIMEFORW_;
    pos_ += grades;
  } 
  
  /* Moves the servo backward */
  if (mode == BACKWARD && grades != 0){
    Backward();
    
    tim = (grades/180)*TIMEBACK_;
    pos_ -= grades;
  }

  delay(tim);
  Stop();
}
