#include <Servo.h>

   
int SERVOPIN = 6;
int BTNPIN = 2; 

Servo serv1;

// Change global variable
int value = 0;
int total = 0;

void setup() {
  Serial.begin(9600);
  serv1.attach(SERVOPIN);
  

  pinMode(BTNPIN, INPUT_PULLUP);  
  serv1.write(0);
}

void loop() {
  // Initial values of each variable
  int vel = 5;
  int lecturas = 6;
  bool push = false;
  int time1;

  int time2 = millis();

   // While the botton is pressed
  while (!digitalRead(BTNPIN)){
    
    push = true;
    time1 = millis();
  }

  // The button is not pressed
 

  // We add the new time value if the button was pressed
  if (push){
    int result = time1 - time2;

    // Serial out
    Serial.print("Value: ");
    Serial.print(value + 1);
    Serial.print(";   Reuslt: ");
    Serial.println(result);
    

    // Store the time if the value is correct
    if (result >= 300){
      total+= result;
      value++;
    }

    push = false;   
  }  
  delay(10);

  // Stops the program 
  while (value == lecturas){
    Serial.print("\nMid time = ");
    Serial.println(total/value);
    while(1);
    
  }
}
