#include "Engines.h"

Engines mymotors(3, 5, 6, 9);
void setup()
{
  mymotors.Drive(100, -100);
}

void loop()
{
  delay(5000);
  mymotors.Change();
}
