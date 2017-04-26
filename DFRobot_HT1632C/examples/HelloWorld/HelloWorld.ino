#include "DFRobot_HT1632C.h"

#define DATA 6
#define CS 2
#define WR 7
//#define RD 7

DFRobot_HT1632C ht1632c = DFRobot_HT1632C(DATA, WR,CS);

char str[] = "Hello";

void setup() {
  // put your setup code here, to run once:
  ht1632c.begin();
  ht1632c.isLedOn(true);
  ht1632c.clearScreen();
	ht1632c.setCursor(0,0);
  ht1632c.print(str);
}

void loop() {
  // put your main code here, to run repeatedly:

}
