#ifndef __SCREEN__
#define __SCREEN__

class Screen {
public:
  virtual void init();
  virtual void print(char* msg, int row, int col);
  virtual void clear();
};

#endif