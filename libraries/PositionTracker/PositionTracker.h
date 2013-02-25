/*
--Probotics, Princeton University--
PositionTracker.h: uses 2 encoders to keep track of position
  compute() should be called frequently
*/

#ifndef PositionTracker_h
#define PositionTracker_h

#include <Arduino.h>
#include <Encoder.h>

class PositionTracker{
  public:
    PositionTracker(Encoder left, Encoder right, double wb);
    void compute();
    
    double getX();
    double getY();
    double getAngle();
    
    void reset();

    double getSpeed();
    double getAngularSpeed();

  private:
    double wheelBase;
    Encoder *leftEncoder;
    Encoder *rightEncoder;
    double x,y,angle;
    int lastLeft, lastRight;
};

#endif