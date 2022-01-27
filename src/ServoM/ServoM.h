
#ifndef SERVOM_H_INCLUDED
#define SERVO_H_INCLUDED

// Heredate original servo?
class ServoM {

  public:
    ServoM(int pin); // Construct
    
    void start(int gear);
    void set_speed(int gear);

  private:
    int PIN;
    int Speed;
    int pos = 0;



    //********* Pulse width values *********
    //** Direction 1
    int MAX1 = 456;
    int MIN1 = 451;

    //** Direction 2
    int MAX2 = 431;
    int MIN2 = 436;

    // Max gear
    int GEAR = 5;

    //********* Gear's calibration *********
    // Time to complete a lap
    TIMEG1 = 0;
    TIMEG2 = 0;
    TIMEG3 = 0;
    TIMEG4 = 0;
    TIMEG5 = 0;

        
    /* Pendiente de implementar:
     *  - Posición en todo momento del servo
     *  - Calibrador de tiempo x vuelta con encoder
     *  - Girar un determinado número de grados
     */
    
     
};

#endif
