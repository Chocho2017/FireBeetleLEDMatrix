#include "DFRobot_HT1632C.h"

#if defined( ESP_PLATFORM ) || defined( ARDUINO_ARCH_FIREBEETLE8266 )  //FireBeetle-ESP32 FireBeetle-ESP8266
#define DATA D6
#define CS D2
#define WR D7
//#define RD D8
#else
#define DATA 6
#define CS 2
#define WR 7
//#define RD 8
#endif

DFRobot_HT1632C ht1632c = DFRobot_HT1632C(DATA, WR,CS);

char msg[][90] =  {{"  this is a test of the non-blocking scrolling function for the HT1632 LedMatrix !!! "},
                {"  its fun  :-)  second message !!     1234567890  "},
                {"  visit the github repository https://github.com/Chocho2017/FireBeetleLEDMatrix  "}};

void setup() {
  ht1632c.begin();
  ht1632c.clearScreen();
	ht1632c.setCursor(0,0);
  ht1632c.startScrolling(msg[0]);
}

void loop() {
  static unsigned long msgTimer = millis();
  static unsigned long ledTimer = millis();
  static uint8_t msgCnt = 0;
  static uint8_t ledState = 0;
   
  if (millis() - msgTimer > 10000) {
    msgTimer = millis();
    msgCnt=(msgCnt+1)%3;
    ht1632c.startScrolling(msg[msgCnt]);
  }
  
  ht1632c.doScrolling (50-msgCnt*15);   // scrolling with variable speed 

}
