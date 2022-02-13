
#include <Servo.h>

#ifndef SERVOM_H_INCLUDED
#define SERVO_H_INCLUDED

class ServoM : public Servo {

  public:
    ServoM(){} // Construct
    
    void turn(int grades);
    void get_pos() { return pos;}
    
    void set_measured(bool mod){ calibrated = mod; }
    bool measure_mode();

    void Forward();
    void Backward();
    void Stop();
    
  private:
    Servo servo; 

    int pos;
    const static int STEP = 5; /* Acceleration */
    /* Pulse width values */
    const static int TACEL = 60;
    const static int LEFT = 83 + STEP;  /* Decrease value to increase velocity */
    const static int RIGHT = 103 - STEP;  /* Increase value to increase velocity */  
    const static int STOP = 90;
    
    


    /* Calibration */
    bool calibrated = false;
    const float TIMEFORW = 9843;  /* Time to complete half loop 180*/
    const float TIMEBACK = 946;
    int min_pos = 0;
    int max_pos = 180;
    

    /* Private methods*/

     
};

#endif
