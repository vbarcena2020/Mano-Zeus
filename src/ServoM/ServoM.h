
#ifndef SERVOM_H_INCLUDED
#define SERVO_H_INCLUDED

// Heredate original servo?
class ServoM {

  public:
    ServoM(int pin); // Construct
    void turn(int grades); // Gear = 5
    void turn(int grades, int gear);
    void set_measured(bool mod){ calibrated = mod; }
    bool measure_mode();

  private:
    bool calibrated = false;
    int PIN;
    int Speed;
    int GEAR;
    int tim;
    int pos = 0;



    //********* Pulse width values *********
    //** Direction 1
    int MAX1 = 456;
    int MIN1 = 451;

    //** Direction 2
    int MAX2 = 431;
    int MIN2 = 436;

    // Max gear
    int MAX_GEAR = 5;

    //********* Gear's calibration *********
    // Time to complete half lap
    int TG1 = 0;
    int TG2 = 0;
    int TG3 = 0;
    int TG4 = 0;
    int TG5 = 900;

    int TIMEG[6] = {0, TG1, TG2, TG3, TG4, TG5};

    //********* Private methods *********
    void start(int gear);
    void set_speed(int gear);

        
    /* Pendiente de implementar:
     *  - Posición en todo momento del servo
     */
    
     
};

#endif
