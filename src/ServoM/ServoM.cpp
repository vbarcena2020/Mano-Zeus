
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
  if (! acelerated_)
  {
    int time_acel =  (TACEL_ * STEP_) + timef_;

    for (int i = 1; i <= STEP_ ; i++)
    {
      if (millis() % 1000 <= (TACEL_ * i) + timef_){ this->write(LEFT_ - i + 1); }
      if (millis()% 1000 <= (TACEL_ * STEP_) + timef_){ acelerated_ = true; }
    }
  }
}


void ServoM::Backward()
{
  if (! acelerated_)
  {
    if (millis() % 1000 >= ((TACEL_ * 1) + time0_) && current_ == 0){ this->write(RIGHT_ ); current_ = 1; Serial.println(RIGHT_ ); return;}
    if (millis() % 1000 >= ((TACEL_ * 2) + time0_) && current_ == 1){ this->write(RIGHT_ + 1); current_ = 2; Serial.println(RIGHT_ + 1); return;}
    if (millis() % 1000 >= ((TACEL_ * 3) + time0_) && current_ == 2){ this->write(RIGHT_ + 2); current_ = 3; Serial.println(RIGHT_ + 2); return; }
    if (millis() % 1000 >= ((TACEL_ * 4) + time0_) && current_ == 3){ this->write(RIGHT_ + 3); current_ = 4; Serial.println(RIGHT_ + 3); return;}
    if (millis() % 1000 >= ((TACEL_ * 5) + time0_) && current_ == 4){ this->write(RIGHT_ + 4); current_ = 5; Serial.println(RIGHT_ + 4); return ;}
    if (millis() % 1000 >= ((TACEL_ * 6) + time0_) && current_ == 5){this->write(RIGHT_ + 5); acelerated_ = true; Serial.println("Telmino");}
    
    
    
    //for (int i = 1; i <= STEP_ ; i++)
    //{
    //  if (millis() <= (TACEL_ * i) + timef_){ this->write(RIGHT_ + i - 1); }
    //  if (millis() <= (TACEL_ * STEP_) + timef_){ acelerated_ = true; }
    //}
  }
}


void ServoM::Stop(){ this->write(STOP_); acelerated_ = false;}

double ServoM::check_grades(double grades)
{
   /* Limit forward*/
   if (pos_ + grades > max_pos_){ grades = max_pos_ - pos_; }
  
   /* Limit backward and changes mode */
   if (grades < 0 && (pos_ + grades) < min_pos_){ grades = min_pos_- pos_; }  

    return grades;
}

void ServoM::turn(double grades)
{
  grades = check_grades(grades);
  if (grades > 0){ mode = FORWARD ;}
  if (grades < 0){ mode = BACKWARD ; grades *= -1; }
  
  

  if (! turning_ && grades != 0)
  {
    int mode = FORWARD;
    time0_ = millis() % 1000;
    Serial.println(time0_);
    timef_ = ((grades/180)*TIMEBACK_) + (millis() % 1000);
    target_ = grades;
    turning_ = true;
  }

  if (! acelerated_ && turning_){
    if (mode == FORWARD) { pos_ += grades; Forward() ;}
    if (mode == BACKWARD) { pos_ -= grades; Backward(); }
  }
  
  if (timef_ <= millis() % 1000)
  {
    Stop();
    target_ = 0;
    turning_ = false;

  }
}

void ServoM::goTo(double grades)
{
  grades -= pos_;
  if (turning_){grades = 0;}
  
  turn(grades);
}
