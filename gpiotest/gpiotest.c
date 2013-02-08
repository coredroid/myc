/*********GPIO TEST BASED ON wiringPi*************/
#include <wiringPi.h>
#include <stdlib.h>

int main()
{
  int i;
  
  if(wiringPiSetup() == -1)
    exit(1);

  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  for(i=0;i<40;i++)
  {
    digitalWrite(i%4,HIGH);
    delay(200);
    digitalWrite(i%4,LOW);
    delay(200);
  }
  return 0;
}
