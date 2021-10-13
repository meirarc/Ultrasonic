/**
 * @file Ultrasonic.h
 * @author meirarc
 * @version 0.1
 * @date 2021-10-13
 * 
 * @copyright Copyright (c) 2021
 * 
 * @brief Ultrasonic.cpp - Library for HC-SR04 Ultrasonic Sensing Module.
 */

#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

class Ultrasonic {    
    public:
        Ultrasonic(int tp, int ep);
        long timing();
        float convert(long microsec, int metric);
        void setDivisor(float value, int metric);
    
        static const int IN = 0;
        static const int CM = 1;

    private:
        int _trigPin;
        int _echoPin;
        float _cmDivisor;
        float _inDivisor;
};

#endif 
