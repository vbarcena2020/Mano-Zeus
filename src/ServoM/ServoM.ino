#include "ServoM.h"

enum
{
  PINSERVO1 = 6,
  PINSERVO2 = 2,
  PINSERVO3 = 3,

  NUMINVALUES = 5,
  DIGITSPERVAL = 1,
};

ServoM servo1;
ServoM servo2;
ServoM servo3;

int valsIn[NUMINVALUES];
int stringLenght = NUMINVALUES * DIGITSPERVAL + 1;
int counter = 0;
bool counterStart = false;
String recivedString;


void setup() 
{
  Serial.begin(9600);
  
  servo1.attach(PINSERVO1);
  servo2.attach(PINSERVO2);
  servo3.attach(PINSERVO3);
}


void receiveData()
{
  while(Serial.available())
  {
     char c = Serial.read();

     if (c=='$') {counterStart = true; }
     
     if (counterStart)
     {
      if (counter < stringLenght)
      {
        recivedString = String(recivedString+c);
        counter++;
      }
      if (counter >= stringLenght){
        for (int i = 0; i < NUMINVALUES ; i++){
          int num = (i*DIGITSPERVAL) + 1;
          valsIn[i] = recivedString.substring(num,num + DIGITSPERVAL).toInt();
        }
        recivedString = "";
        counter = 0;
        counterStart = false;
        
      }
     }
  }
}

void loop() 
{
  receiveData();
  if (valsIn[0] == 1){servo1.goTo(180); }
  else {servo1.goTo(0); }
  if (valsIn[1] == 1){servo2.goTo(180); }
  else {servo2.goTo(0); }
  if (valsIn[4] == 1){servo3.goTo(180); }
  else {servo3.goTo(0); }
  }
