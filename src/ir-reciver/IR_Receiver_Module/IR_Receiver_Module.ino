#include "IRremote.h"

int receiver = 2; 


IRrecv irrecv(receiver);   
decode_results results;      


void translateIR() // takes action based on IR code received

{

  switch(results.value)

  {
  // Power
  case 0xFFA25D: Serial.println("POWER"); break;
  
  // Func/Stop
  case 0xFFE21D: Serial.println("FUNC/STOP"); break;
  
  // Vol+
  case 0xFF629D: Serial.println("VOL+"); break;

  // Vol -
  case 0xFFA857: Serial.println("VOL-");    break;
  
  // Fast back
  case 0xFF22DD: Serial.println("FAST BACK");    break;

  // Pause
  case 0xFF02FD: Serial.println("PAUSE");    break;

  // Fast forward
  case 0xFFC23D: Serial.println("FAST FORWARD");   break;

  // Down
  case 0xFFE01F: Serial.println("DOWN");    break;

  // Up
  case 0xFF906F: Serial.println("UP");    break;

  // Eq
  case 0xFF9867: Serial.println("EQ");    break;

  // ST/REPT
  case 0xFFB04F: Serial.println("ST/REPT");    break;

  // 0
  case 0xFF6897: Serial.println("0");    break;

  // 1
  case 0xFF30CF: Serial.println("1");    break;

  // 2
  case 0xFF18E7: Serial.println("2");    break;

  // 3
  case 0xFF7A85: Serial.println("3");    break;

  // 4
  case 0xFF10EF: Serial.println("4");    break;

  // 5
  case 0xFF38C7: Serial.println("5");    break;

  // 6
  case 0xFF5AA5: Serial.println("6");    break;

  // 7
  case 0xFF42BD: Serial.println("7");    break;

  // 8
  case 0xFF4AB5: Serial.println("8");    break;

  // 9
  case 0xFF52AD: Serial.println("9");    break;

  // Not located signal  
  default: 
    Serial.println(" other button");

  }

  delay(500);


} //END translateIR


void setup() 
{
  Serial.begin(9600);
  Serial.println("Calibration of IR"); 
  irrecv.enableIRIn();

}


void loop()   
{
   // have we received an IR signal?
  if (irrecv.decode(&results))

  {
    translateIR(); 
    // receive the next value
    irrecv.resume(); 
  }  
}
