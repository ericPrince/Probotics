#include <Encoder.h>

int pin1=1;
int pin2=2;

Encoder myEnc = Encoder(pin1,pin2,1.5,24,100);

void setup(){
  attachInterrupt(pin1,encEvent,CHANGE);
  Serial.begin(9600);
}
void loop(){
  double dist  = myEnc.getDistance();
  Serial.print(dist,3);
  System.print("  ");
  double speed = myEnc.getSpeed();
  Serial.println(speed,3);
}
//this function is needed as an interrupt
void encEvent(){
  myEnc.encoderEvent();
}
