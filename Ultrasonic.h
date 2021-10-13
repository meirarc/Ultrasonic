#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>
#include <stddef.h>


//typedef struct bufferCtl
//    {
//    float *pBegin;
//    float *pIndex;
//    size_t length;
//    bool filled;
//    } BufCtl;

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
