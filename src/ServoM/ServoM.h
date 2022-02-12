
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

    /* Pulse width values */
    const static int LEFT = 83;  /* Decrease value to increase velocity */
    const static int RIGHT = 98;  /* Increase value to increase velocity */  
    const static int STOP = 93;
    
    const static int STEP = 5; /* Acceleration */


    /* Calibration */
    bool calibrated = false;
    static const int TIMEHALF = 860;  /* Time to complete half loop */
    int min_pos = 0;
    int max_pos = 180;
    

    /* Private methods*/

     
};

#endif
