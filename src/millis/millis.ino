
void setup()
{
   Serial.begin(9600);
}

int get_millis()
{
   int millisec = millis() % 10000;  // Returns a value with 4 digits
   millisec += 10000;

   return millisec;
}

void loop()
{
  long prueba = 1;
   if (prueba > 0 ){
    prueba = millis();
    Serial.println(prueba);
   }
   
}
