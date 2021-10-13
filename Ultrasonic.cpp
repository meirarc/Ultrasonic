/**
 * @file Ultrasonic.cpp
 * @author meirarc
 * @version 0.1
 * @date 2021-10-13
 * 
 * @copyright Copyright (c) 2021
 * 
 * @brief Ultrasonic.cpp - Library for HC-SR04 Ultrasonic Sensing Module.
 */

#include <Ultrasonic.h>

/**
 * @brief Construct a new Ultrasonic:: Ultrasonic object
 * 
 * @param tp Pin to Trigger
 * @param ep Pin to Echo
 */
Ultrasonic::Ultrasonic(int tp, int ep) {
    pinMode(tp, OUTPUT);
    pinMode(ep, INPUT);
    _trigPin = tp;
    _echoPin = ep;
    _cmDivisor = 27.6233;
    _inDivisor = 70.1633;
}

/**
 * @brief return the timing in microseconds
 * 
 * @return long 
 */
long Ultrasonic::timing() {
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);
    return pulseIn(_echoPin, HIGH);
}

/**
 * @brief   convert the timing in microseconds in Centimeter (CM) or Inches (IN)
 *          refers to Ultrasonic:CM and Ultrasonic:IN
 * 
 * @param microsec 
 * @param metric 
 * @return float 
 */
float Ultrasonic::convert(long microsec, int metric) {
    // microsec / 29 / 2;
    if(metric) return microsec / _cmDivisor / 2.0;  // CM
    // microsec / 74 / 2;
    else return microsec / _inDivisor / 2.0;  // IN
}

/**
 * @brief to update the divisor for IN or CM
 * Centimeters Divisor
 * =========== =======
 *  15.875     26.9029
 *  46.355     27.6233
 *  92.075     28.1949
 * 137.795     28.4717
 * 183.515     28.5584
 * 229.235     28.5936
 * 274.955     28.7194
 *
 * Inches      Divisor
 * ======      =======
 *   6.25      68.3333
 *  18.25      70.1633
 *  36.25      71.6152
 *  54.25      72.3182
 *  72.25      72.5384
 *  90.25      72.6277
 * 108.25      72.9473
 * 
 * @param value 
 * @param metric 
 */
void Ultrasonic::setDivisor(float value, int metric) {
    if(metric) _cmDivisor = value;
    else _inDivisor = value;
}