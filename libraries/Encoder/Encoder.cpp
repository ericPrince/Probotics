#include <arduino.h>
#include <Encoder.h>

Encoder::Encoder(int pA, int pB, double r, double cpr, int t){
  radius=r;
  countPerRev=cpr;
  timeout=t;
  pinA=pA;
  pinB=pB;
}
Encoder::Encoder(){
  radius=0;
  countPerRev=24;
  timeout=100;
  pinA=2;
  pinB=3;
}
  
double Encoder::getDistance(){
  return distance;
}
double Encoder::getSpeed(){
  if(millis()-lastTime>=timeout){
    speed=0;
    lastTime=millis()-timeout;
  }
  return speed;
}
double Encoder::getCount(){
  return count;
}
void Encoder::setTimeout(int t){
  timeout=t;
}
void Encoder::reset(){
  count=0;
  distance=0;
  speed=0;
}
double Encoder::distancePerCount(){
  return 2*PI*radius/countPerRev;
}
 //handled automatically
void Encoder::encoderEvent(){
  int temp=millis();
  double period=((double)(temp-lastTime))/1000;
  lastTime=temp;
  speed=(*this).distancePerCount()/period;
  if(speed>100) speed=0;
  
  if(digitalRead(pinA)==digitalRead(pinB)){
    count++;
  }else{
    count--;
    speed*=-1;
  }
  distance=(double)count*(*this).distancePerCount();
}