/*********************************************************************
This library is inspired by the Adafruit_SSD1306 library from Adafruit
written by Limor Fried/Ladyada  for Adafruit Industries. The original 
library is BSD licensed.

Just like SKAARHOJ, Adafruit also invests time and resources providing 
open source code, so SKAARHOJ encourage you to support Adafruit and 
open-source hardware by purchasing products from Adafruit as well!
*********************************************************************/


#include "Arduino.h"
#include <Adafruit_GFX.h>

#if defined(ARDUINO_SKAARDUINO_V1)  
	#include <SPI.h>
#endif

#define BLACK 0
#define WHITE 1

#define SKAARHOJOLED64x256_LCDWIDTH                  256
#define SKAARHOJOLED64x256_LCDHEIGHT                 64


class SkaarhojOLED64x256 : public Adafruit_GFX {
 public:
  void drawPixel(int16_t x, int16_t y, uint16_t color);

  SkaarhojOLED64x256();
  void begin(uint8_t address);

  void sendCommand(uint8_t c, uint8_t cs);
  void sendData(uint8_t c, uint8_t cs);

  void clearDisplay(void);
  void invertDisplay(bool i, uint8_t cs);
  void display(uint8_t cs);


 private:
	uint8_t _boardAddress, _dataPin, _clockPin, _cs;
	bool _dc, _rst, _vcc;
  void fastSPIwrite(uint8_t c);

  	void chipSelect(uint8_t cs);
	void setDC(bool dc);
	void setVCC(bool dc);
	void writeControlPins();

  volatile uint8_t *mosiport, *clkport;
  uint8_t mosipinmask, clkpinmask;
};
