#include "Engines.h"

Engines:: Engines (int right_engine_input_p,
                   int right_engine_input_m,
                   int left_engine_input_p,
                   int left_engine_input_m):
  Right(right_engine_input_p, right_engine_input_m), Left(left_engine_input_p, left_engine_input_m)
{
  RightBeckup = Right;
  LeftBeckup = Left;
}

void Engines:: Drive(int leftNewSpeed, int rightNewSpeed)
{
  Right.Drive(rightNewSpeed);
  Left.Drive(leftNewSpeed);
}

void Engines::Drive(bool LeftB, bool RightB)
{
  Right.Drive(RightB);
  Left.Drive(LeftB);
}

void Engines::Drive(int Speed)
{
  Drive(Speed, Speed);
}

void Engines::Drive(bool forward)
{
  Drive(forward, forward);
}

void Engines::Drive()
{
  Right.Drive();
  Left.Drive();
}

void Engines::Change()
{
  Right.Change();
  Left.Change();
}

void Engines::TurnOff()
{
  Right.TurnOff();
  Left.TurnOff();
}

int Engines::Speed()
{
  return (round((Right.Speed() + Left.Speed()) / 2));
}

void Engines::Break()
{
  Change();
  delay(250);
  Change();
  TurnOff();
}

void Engines::Acc()
{
  Right.Acc(10);
  Left.Acc(10);
}

void Engines::Acc(int add)
{
  Right.Acc(add);
  Left.Acc(add);
}

void Engines::Slow()
{
  Acc(-10);
}

void Engines::Slow(int Speed)
{
  Acc(-Speed);
}

void Engines::Speed(int add)
{
  Right.Speed(add);
  Left.Speed(add);
}

bool Engines::Forward()
{
  return (Right.Speed() > 0 && Left.Speed() > 0);
}

bool Engines::Backward()
{
  return (Right.Speed() < 0 && Left.Speed() < 0);
}

bool Engines::Turning()
{
  return ((!Forward()) && (!Backward()));
}

void Engines::Slalom(int Length, int Width, bool turnright)
{
  Length = Length * 200;
  Width = map(Width, 1, 100, 1, 40);
  if (!turnright)
  {
    Replace();
  }

  Drive(70 + Width, 70 - Width);
  delay(Length);

  for (int i = 0; i < (2 * Width); ++i)
  {
    Left.Slow(1);
    Right.Acc(1);
    delay(Length);
  }

  for (int i = 0; i < (2 * Width); ++i)
  {
    Left.Acc(1);
    Right.Slow(1);
    delay(Length);
  }

  if (!turnright)
  {
    Replace();
  }
}

void Engines::Slalom(int Length, int Width, bool turnright, int Steps)
{
  for (int i = 0; i < Steps; ++i)
  {
    Slalom(Length, Width, turnright);
  }
}

void Engines::Slalom(int Length, int Width, int Steps)
{
  Slalom(Length, Width, true, Steps);
}

void Engines::Slalom(int Length, int Width)
{
  Slalom(Length, Width, true);
}

void Engines::Slalom(bool turnright)
{
  Slalom(20, 70, turnright);
}

void Engines::Slalom(int Steps)
{
  Slalom(20, 70, true, Steps);
}

void Engines::Slalom()
{
  Slalom(20, 30, true);
}

void Engines::Replace()
{
  Engine temp = Right;
  Right = Left;
  Left = temp;
}

void Engines::DisReplace()
{
  Right = RightBeckup;
  Left = LeftBeckup;
}
