
#include <Servo.h>

#ifndef SERVOM_H_INCLUDED
#define SERVO_H_INCLUDED

class ServoM : public Servo {

  public:
    ServoM(){} // Construct
    
    void turn(double grades);
    void get_pos() { return pos_;}

    
  private:
    Servo servo_; 

    int pos_;
    const static int STEP_ = 5; /* Acceleration */
    
    /* Pulse width values */
    const static int TACEL_ = 60;
    const static int LEFT_ = 83 + STEP_;  /* Decrease value to increase velocity */
    const static int RIGHT_ = 103 - STEP_;  /* Increase value to increase velocity */  
    const static int STOP_ = 90;
    
    


    /* Calibration */
    bool calibrated_ = false;
    const float TIMEFORW_ = 843;  /* Time to complete half loop 180º */
    const float TIMEBACK_ = 826;
    int min_pos_ = 0;
    int max_pos_ = 180;
    

    /* Private methods*/ 
    void Forward();
    void Backward();
    void Stop();

    double check_grades(double grades);
     
};

#endif
