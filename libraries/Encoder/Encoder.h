/*
--Probotics, Princeton University--
Encoder.h: used to decode a 2-signal encoder
  encoderEvent() is attached to an interrupt
made for arduino 1.5.1 on Feb 4, 2013
*/


#ifndef Encoder_h
#define Encoder_h

#include <Arduino.h>

class Encoder{
  private:
    volatile double speed;
    volatile double distance;
    volatile int count;
    volatile int lastTime;
  
    double radius, countPerRev;
    int pinA, pinB, timeout;
  public:
    Encoder(int pA, int pB, double r, double cpr, int t);
    Encoder();
  
    double getDistance();
    double getSpeed();
    double getCount();
    void setTimeout(int t);
    void reset();
    double distancePerCount();

    void encoderEvent();
};

#endif