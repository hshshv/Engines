#ifndef Engine_h
#define Engine_h

#include "Arduino.h"
class Engine
{
  private:
    int PlusOrAnalogPin;
    int MinusOrDirectionPin;
    int DSpeed = 100;
    int MySpeed = 0;
    bool normal = true;
    int MyCompensation = 0;
    int SortOfDriver = 293; //defulte > L293d Engines Driver
  public:
    Engine(int NPlusOrAnalogPin, int NMinusOrDirectionPin, int NSortOfDriver);
    Engine(int NPlusOrAnalogPin, int NMinusOrDirectionPin);
    Engine();
    int Speed();
    int Compensation();
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
    void Compensation(int NCompensation);
};
#endif
