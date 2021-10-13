#include <Ultrasonic.h>

#define TRIGGER_PIN  12
#define ECHO_PIN     13

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

void setup()
  {
  Serial.begin(9600);
  }

void loop()
  {
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();

  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  Serial.print("MS: ");
  Serial.print(microsec);
  Serial.print(", CM: ");
  Serial.print(cmMsec);
  Serial.print(", IN: ");
  Serial.println(inMsec);
  delay(1000);
  }
