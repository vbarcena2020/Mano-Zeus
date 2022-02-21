
#include <Servo.h>

#ifndef SERVOM_H_INCLUDED
#define SERVO_H_INCLUDED

class ServoM : public Servo {

  public:
    ServoM(){} // Construct
    
    void turn(double grades);
    void goTo(double grades);
    double get_pos() { return pos_;}

    
  private:
    Servo servo_; 

    int pos_ = 0;
    int mode  = 0;
    const static int STEP_ = 5; /* Acceleration */
    int current_= 0;
    int target_ ;
    bool acelerated_= false;
    int timef_;
    int time0_;
    bool turning_ = false;
    
    /* Pulse width values */
    const static int TACEL_ = 60;
    const static int LEFT_ = 83 + STEP_;  /* Decrease value to increase velocity */
    const static int RIGHT_ = 103 - STEP_;  /* Increase value to increase velocity */  
    const static int STOP_ = 90;
    
    


    /* Calibration */
    bool calibrated_ = false;
    const float TIMEFORW_ = 843;  /* Time to complete half loop 180º */
    const float TIMEBACK_ = 1400;
    int min_pos_ = -180;
    int max_pos_ = 180;
    

    /* Private methods*/ 
    void Forward();
    void Backward();
    void Stop();

    double check_grades(double grades);
     
};

#endif
