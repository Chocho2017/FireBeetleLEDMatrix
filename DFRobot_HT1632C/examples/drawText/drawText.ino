#include "DFRobot_HT1632C.h"

#define DATA 6
#define CS 2
#define WR 7
//#define RD 7

DFRobot_HT1632C ht1632c = DFRobot_HT1632C(DATA, WR,CS);

char text[] = "123";

void setup() {
  // put your setup code here, to run once:
  ht1632c.begin();
  ht1632c.isLedOn(true);
  ht1632c.clearScreen();
}

void loop() {
  // put your main code here, to run repeatedly:
  ht1632c.drawText(text, 0, 0, FONT_8X4, FONT_8X4_END, FONT_8X4_HEIGHT);
  ht1632c.writeScreen();
  delay(1000);
}
