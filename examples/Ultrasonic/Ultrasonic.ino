#include <Arduino.h>
#include <Ultrasonic.h>

#define TRIGGER_PIN  4
#define ECHO_PIN     5

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

void setup() {
  Serial.begin(9600);
}

void loop() {
  float msecToCM, msecToIN;
  long microsec = ultrasonic.timing();

  msecToCM = ultrasonic.convert(microsec, Ultrasonic::CM);
  msecToIN = ultrasonic.convert(microsec, Ultrasonic::IN);
  Serial.print("MicroSec: ");
  Serial.print(microsec);
  Serial.print(", CM: ");
  Serial.print(msecToCM);
  Serial.print(", IN: ");
  Serial.println(msecToIN);
  delay(1000);
}