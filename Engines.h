#ifndef Engines_h
#define Engines_h

#include "Arduino.h"
#include "Engine.h"
class Engines
{
  private:
    Engine RightBeckup;
    Engine LeftBeckup;
  public:
    Engines(int right_engine_input_p,
            int right_engine_input_m,
            int left_engine_input_p,
            int left_engine_input_m);
    Engine Right;
    Engine Left;
    void Drive(int LeftSpeed, int RightSpeed);
    void Drive(bool LeftB, bool RightB);
    void Drive(int Speed);
    void Drive(bool forward);
    void Drive();
    void Change();
    void TurnOff();
    void Break();
    int Speed();
    void Speed(int add);
    void Acc();
    void Acc(int Speed);
    void Slow();
    void Slow(int Speed);
    bool Forward();
    bool Backward();
    bool Turning();
    void Slalom(int Length, int Width, bool turnright, int Steps);//V
    void Slalom(int Length, int Width, int Steps);
    void Slalom(int Length, int Width, bool turnright);//Vbase
    void Slalom(int Length, int Width);
    void Slalom(bool turnright);
    void Slalom(int Steps);
    void Slalom();
    void Replace();
    void DisReplace();
};
#endif
