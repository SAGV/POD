// To flash my sw
// Use this manual to be able to flash attiny85 via arduino IDE https://www.instructables.com/id/How-to-Program-an-Attiny85-From-an-Arduino-Uno/
// Don't forget to set internal clock to 16Mhz and board to attiny85 in arduino ide -> tools
#include <avr/sleep.h>

#define workInterv  33750 //9 * 60 * 1000 / 16 
#define breakInterv 10875 //3 * 60 * 1000 / 16 
#define flashInterv 250 / 16 //250 / 16
#define intermediateDelay 1000 / 16

void setup()
{

  for(int i=0; i<=4; i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }

  delay(flashInterv);
  for(int j=0; j<=4; j++)
    digitalWrite(j, LOW);
  
  delay(flashInterv);
  for(int j=0; j<=4; j++)
    digitalWrite(j, HIGH);

  for(int i=0; i<=4; i++)
  {
    delay(workInterv);
    digitalWrite(i, LOW);
  }
  delay(intermediateDelay);

  for(int i=0; i<=9; i++)
  {
    for(int j=0; j<=4; j++)
      digitalWrite(j, HIGH);
    delay(flashInterv);
    for(int j=0; j<=4; j++)
      digitalWrite(j, LOW);
    delay(flashInterv);
  }

  // break
  for(int i=0; i<=4; i++) digitalWrite(i, HIGH);

  for(int i=0; i<=4; i++)
  {
    delay(breakInterv);
    digitalWrite(i, LOW);
  }
  delay(intermediateDelay);

  for(int i=0; i<=9; i++)
  {
    for(int j=0; j<=4; j++)
      digitalWrite(j, HIGH);
    delay(flashInterv);
    for(int j=0; j<=4; j++)
      digitalWrite(j, LOW);
    delay(flashInterv);
  }

  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_mode();
}

void loop()
{
}
