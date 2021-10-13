# Ultrasonic
This library was created to work with the HC-SR04 Ultrasonic sensor.

It features timing, metric conversion (centimeter and inch) and standard
deviation methods.

## Install

1. Download the code
2. Add the folder under `Arduino/libraries`
3. Restart Arduino IDE

## Library details

Public functions:

- `Ultrasonic(int tp, int ep)`

    Contructor, inform the pin number of the trigger (`tp`) and echo (`ep`)

- `long timing()`

    to calculate the timing in microseconds

- `float convert(long microsec, int metric)`

    to convert the microseconds in IN or CM
    Use the variables `Ultrasonic:IN` or `Ultrasonic:CM` on the `metric`

- `void setDivisor(float value, int metric)`

    set new divisor `value` to the `metric` in case need to adjust the precision


## Example

```c++
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
```