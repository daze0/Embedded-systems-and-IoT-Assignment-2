#include "AbstractButton.h"
#include "Arduino.h"

ButtonImpl::AbstarctButton(int pin){
  this->pin = pin;
  pinMode(pin, INPUT);  
  sync();   
} 
  
bool ButtonImpl::isPressed(){
  return pressed;
}

void ButtonImpl::sync(){
  pressed = digitalRead(pin) == HIGH;
  updateSyncTime(millis());
}

