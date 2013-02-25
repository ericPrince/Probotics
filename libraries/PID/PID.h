/*
--Probotics, Princeton University--
PID.h: used for standard PID control
  the main method is compute() which should
  be called every time loop() runs
made for arduino 1.5.1 on Feb 4, 2013
*/

#ifndef PID_h
#define PID_h

#include <Arduino.h>

const double PWM_MAX=255;

class PID{
  public:
    PID(double p,double i,double d,double lo,double hi);
    PID(double p,double i,double d);
    double compute(double input, double setPoint);
    void reset();
    void setConstants(double p,double i,double d);

  private:
    double kp,ki,kd, outMin,outMax;
    double iTerm;
    unsigned long lastT;
    double lastInput;
};

#endif