#include "Engine.h"

Engine::Engine(int NPlusPin, int NMinusPin)
{
  PlusPin = NPlusPin;
  MinusPin = NMinusPin;
  pinMode(PlusPin, OUTPUT);
  pinMode(MinusPin, OUTPUT);
}

Engine::Engine()
{
  Engine(5, 6);
}

int Engine::Speed()//absulot value
{
  return (MySpeed);
}

void Engine::Speed(int add)//אם הוא נוסע אחורה ומאיצים - הוא מאט ומתחיל לאט לאט לנסוע קדימה.
{
  if (add == 0)
  {
    return;
  }
  if(!Forward())
  {
    add = add * (-1);
  }
    Acc(add);
}

void Engine::Drive(int Speed)
{
  if (Speed > 100)
  {
    Speed = 100;
  }
  if (Speed < -100)
  {
    Speed = -100;
  }
  if (!normal)
  {
    Speed = Speed * (-1);
  }

  TurnOff();
  MySpeed = Speed;
  if (MySpeed > 0)
  {
    analogWrite(PlusPin, map(Speed, 0, 100, 0, 255));
  }
  if (MySpeed < 0)
  {
    analogWrite(MinusPin, map(abs(Speed), 0, 100, 0, 255));
  }
}

void Engine::Drive(bool forward)
{
  if(MySpeed == 0)
  {
    MySpeed = DSpeed;
  }
  if (forward)
  {
    Drive(abs(MySpeed));
  }
  else
  {
    Drive(-abs(MySpeed));
  }
}

void Engine::Drive()
{
  Drive(DSpeed);
}

void Engine::Change()
{
  Drive(!Forward());
}

void Engine::Break()
{
  Change();
  delay(250);
  TurnOff();
}

void Engine::Acc()
{
  Acc(10);
}

void Engine::Acc(int Speed)//אם הוא נוסע אחרוה ומאיצים - הוא נוסע אחורה יותר מהר.
{
  if(MySpeed == 0 && Speed < 0)
  {
    return;
  }
  if (Forward())
  {
    Drive(MySpeed  + Speed);
  }
  else
  {
    Drive(MySpeed - Speed);
  }
}

void Engine::Slow()
{
  Acc(-10);
}

void Engine::Slow(int Speed)
{
  Acc(-Speed);
}

void Engine::TurnOff()
{
  digitalWrite(PlusPin, LOW);
  digitalWrite(MinusPin, LOW);
  MySpeed = 0;
}

bool Engine::Forward()
{
  return (MySpeed >= 0);
}

void Engine::Reverse()
{
  normal = false;
}

void Engine::Straight()
{
  normal = true;
}

bool Engine::Backward()
{
  return(MySpeed < 0);
}
