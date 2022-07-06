#ifndef __BUTTONIMPL__
#define __BUTTONIMPL__

#include "Button.h"

class ButtonImpl: public Button{

public:
    ButtonImpl(int pin);
    bool isPressed();
    void sync();
    int getPin();

private:
    int pin;
    bool pressed;
};

#endif