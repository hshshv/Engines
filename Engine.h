#ifndef Engine_h
#define Engine_h

#include "Arduino.h"
class Engine
{
  private:
    int PlusPin;
    int MinusPin;
    int DSpeed = 100;
    int MySpeed = 0;
    bool normal = true;
  public:
    Engine(int NPlusPin, int NMinusPin);
    Engine();
    int Speed();
    void Speed(int add);
    void Drive(int Speed);
    void Drive(bool forward);
    void Drive();
    void Change();
    void Break();
    void Acc();
    void Acc(int Speed);
    void Slow();
    void Slow(int Speed);
    void TurnOff();
    bool Forward();
    bool Backward();
    void Reverse();
    void Straight();
};
#endif
