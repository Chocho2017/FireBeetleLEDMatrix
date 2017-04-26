#include "DFRobot_HT1632C.h"

#define DATA 6
#define CS 2
#define WR 7
//#define RD 7

DFRobot_HT1632C ht1632c = DFRobot_HT1632C(DATA, WR,CS);

char str[] = " DFROBOT 2017";

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  ht1632c.begin();
  ht1632c.isLedOn(true);
  ht1632c.clearScreen();
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  ht1632c.print(str,50);
  //delay(100);
}
