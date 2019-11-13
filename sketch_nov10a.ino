#include<SoftwareSerial.h>
SoftwareSerial BTSerial(7,8);

void setup()
{
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop()
{
  int val=analogRead(A0);
  int mappedValue=map(val,0,1023,0,255);
  
  if(BTSerial.available()){
    Serial.write(BTSerial.read());
  }
  if(Serial.available()){
    BTSerial.write(Serial.read());
    BTSerial.println(mappedValue);
  }
}
