#include <Arduino.h>
#include <PositionTracker.h>
#include <Encoder.h>

PositionTracker::PositionTracker(Encoder left, Encoder right, double wb){
  leftEncoder  = &left;
  rightEncoder = &right;
  wheelBase = wb;
  reset();
}
void PositionTracker::compute(){
  int nL=(*leftEncoder).getCount()-lastLeft;
  lastLeft+=nL;
  int nR=(*rightEncoder).getCount()-lastRight;
  lastRight+=nR;
  
  double ds = (*leftEncoder).distancePerCount() * (nR+nL)/2;
  x+=ds*cos(angle);
  y+=ds*sin(angle);
  if(nL!=nR){
    angle+=(*leftEncoder).distancePerCount()/wheelBase*(nR-nL);
  }
}

double PositionTracker::getX(){ return x; }
double PositionTracker::getY(){ return y; }
double PositionTracker::getAngle(){ return angle; }

void PositionTracker::reset(){
  x=0;
  y=0;
  angle=0;
  lastLeft=0;
  lastRight=0;
}

double PositionTracker::getSpeed(){
  return ((*leftEncoder).getSpeed()+(*rightEncoder).getSpeed())/2;
}
double PositionTracker::getAngularSpeed(){
  return ((*rightEncoder).getSpeed()-(*leftEncoder).getSpeed())/wheelBase;
}