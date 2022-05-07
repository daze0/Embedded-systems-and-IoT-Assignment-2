#include "ServoMotorImpl.h"
#include "TimerOne.h"


int pos;   
int delta;
ServoMotor* pMotor;
bool isActive;
bool Tmaking;
int count;
long time0;
long time1;

void setup() {
  Serial.begin(9600);
  pMotor = new ServoMotorImpl(2);
  Timer1.initialize(27777);
  Timer1.attachInterrupt(tick);  
  Timer1.start();
  pos = 0;
  delta = 1;
  isActive = false;
  Tmaking = false;  
}

void tick(){  
  if(!isActive){
    pMotor->on();
    isActive=true;
    time0 = millis();
  }
  pMotor->setPosition(pos);
  pos += delta;
  Serial.println(pos);  
  if(pMotor->readPosition()==2750){
    time1 = millis();
    Serial.println("elapsed: " + String(time1-time0));   
    Tmaking = true;
  }
  
}

void loop() {
  if(Tmaking){
    
    pos = 0;
    pMotor->setPosition(pos);
    pMotor->off();   
    isActive = false;     
    Tmaking = false;
  }
}