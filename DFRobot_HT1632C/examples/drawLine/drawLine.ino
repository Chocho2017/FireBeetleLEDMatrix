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

char text[] = "123";

void setup() {
  // put your setup code here, to run once:
  ht1632c.begin();
  ht1632c.isLedOn(true);
  ht1632c.clearScreen();

  ht1632c.drawLine(0, 0, 0, 7);
  ht1632c.drawLine(0, 7, 23, 7);
  ht1632c.drawLine(23, 7, 23, 0);
  ht1632c.drawLine(0, 0, 23, 0);
  ht1632c.writeScreen();
}

void loop() {
  // put your main code here, to run repeatedly:
  for(uint8_t i = 1; i < 16; i++){
    ht1632c.setPwm(i);
    delay(50);
  }
  for(uint8_t i = 15; i > 0; i--){
    ht1632c.setPwm(i);
    delay(50);
  }
}
