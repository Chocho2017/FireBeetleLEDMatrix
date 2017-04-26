#include "DFRobot_HT1632C.h"

#define DATA 6
#define CS 2
#define WR 7
//#define RD 7

DFRobot_HT1632C ht1632c = DFRobot_HT1632C(DATA, WR,CS);

void setup() {
  // put your setup code here, to run once:
  ht1632c.begin();
  ht1632c.isLedOn(true);
  ht1632c.clearScreen();
}

void loop() {
  // put your main code here, to run repeatedly:
  for(uint8_t x=0; x<24; x++){
    for(uint8_t y=0; y<8; y++){
      ht1632c.setPixel(x,y);   
      ht1632c.writeScreen(); 
      delay(100);
    }
  }

  for(uint8_t x=0; x<24; x++){
    for(uint8_t y=0; y<8; y++){
      ht1632c.clrPixel(x,y);   
      ht1632c.writeScreen(); 
      delay(100);
    }
  }
}
