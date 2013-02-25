#include <Arduino.h>
#include <PID.h>

PID::PID(double p,double i,double d,double lo,double hi){
  kp=p; ki=i; kd=d;
  outMin=lo; outMax=hi;
  iTerm=0;
  
  lastT=millis();
  lastInput=0;
}
PID::PID(double p,double i,double d){
  kp=p;
  ki=i;
  kd=d;
  outMin=0;
  outMax=255;
}
  
double PID::compute(double input, double setPoint){
  double error = setPoint - input;
  int temp=millis();
  double dt=temp-lastT;    
  
  iTerm+= (ki * error * dt/1000);
  if(iTerm > outMax) iTerm= outMax;
  else if(iTerm < outMin) iTerm= outMin;
  double dInput = (input - lastInput);

  double output = kp * error + iTerm- kd * dInput;     
  if(output > outMax) output = outMax;
  else if(output < outMin) output = outMin;
  
  lastInput = input;
  lastT = temp;

  return output;
}
void PID::reset(){
  iTerm=0;
  lastT=millis();
  lastInput=0;
}
void PID::setConstants(double p,double i,double d){
  kp=p; ki=i; kd=d;
}