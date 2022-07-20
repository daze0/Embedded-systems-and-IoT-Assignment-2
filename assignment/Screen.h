#ifndef __SCREEN__
#define __SCREEN__

class Screen {
public:
    virtual void init();
    virtual void print(char* msg);
    virtual void clear();
    virtual void setCursor(int rows, int cols);
    virtual void backlight();
};

#endif