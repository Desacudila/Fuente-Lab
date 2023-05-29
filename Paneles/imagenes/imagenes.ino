#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library

#define TFT_DC         9    // pin tft
#define TFT_RST        8    // pin tft
#define TFT_CS         10   // pin tft

#define ST7735_BLACK 0x0000
#define ST7735_LIGHT_GRAY 0xBDF7
#define ST7735_DARK_GRAY 0x7BEF
#define ST7735_ORANGE 0xFBE0
#define ST7735_BROWN 0x79E0
#define ST7735_PINK 0xF81F
#define ST7735_BLUE 0x001F
#define ST7735_RED 0xF800
#define ST7735_GREEN 0x07E0
#define ST7735_CYAN 0x07FF
#define ST7735_MAGENTA 0xF81F
#define ST7735_YELLOW 0xFFE0
#define ST7735_WHITE 0xFFFF

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);

const unsigned char cooler_icon [] PROGMEM = {

0x08, 0xc0, 
0x19, 0xf0, 
0x39, 0xc0, 
0x39, 0x88, 
0x19, 0xbe, 
0xcf, 0xfe, 
0xce, 0xf6, 
0xfd, 0x70, 
0xfe, 0xf8, 
0x07, 0xfc, 
0x0f, 0x9e, 
0x7e, 0xce, 
0x3c, 0xcc, 
0x19, 0xc8, 
0x03, 0x80

};

const unsigned char temp_icon [] PROGMEM = {

0x18, 
0x24, 
0x2c, 
0x24, 
0x2c, 
0x24, 
0x24, 
0x24, 
0x42, 
0x99, 
0xbd, 
0xbd, 
0x99, 
0x42, 
0x3c

};

void setup() {
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(3);
  tft.fillScreen(ST7735_BLACK);
}

void loop() {

tft.drawBitmap(138,101,cooler_icon,15,15,ST7735_BLUE);
tft.drawBitmap(11,101,temp_icon,8,15,ST7735_BLUE);

tft.drawLine(0, 0, 160, 0, ST7735_CYAN);
tft.drawLine(0, 0, 0, 128, ST7735_CYAN);
tft.drawLine(0, 127, 160, 127, ST7735_CYAN);
tft.drawLine(159, 0, 159, 128, ST7735_CYAN);

tft.drawLine(0, 99, 160, 99, ST7735_CYAN);
tft.drawLine(30, 113, 131, 113, ST7735_CYAN);

tft.drawLine(131, 99, 131, 127, ST7735_CYAN);
tft.drawLine(29, 99, 29, 127, ST7735_CYAN);
tft.drawLine(81, 99, 81, 113, ST7735_CYAN);

tft.drawLine(0, 33, 160, 33, ST7735_CYAN);
tft.drawLine(0, 66, 160, 66, ST7735_CYAN);


  tft.setCursor(4, 118);
  tft.setTextColor(ST7735_WHITE);
  tft.setTextSize(0);
  tft.println("20 C");
  tft.setCursor(17, 113);
  tft.print(".");

  tft.setCursor(134, 118);
  tft.setTextColor(ST7735_WHITE);
  tft.setTextSize(0);
  tft.println("100%");
  
  tft.setTextColor(ST7735_GREEN);
  tft.setCursor(9, 6);
  tft.setTextSize(3);
  tft.println("V:30.000");
  tft.setTextColor(ST7735_YELLOW);
  tft.setCursor(9, 39);
  tft.setTextSize(3);
  tft.println("I:05.000");
  tft.setTextColor(ST7735_MAGENTA);
  tft.setCursor(9, 72);
  tft.setTextSize(3);
  tft.println("W:180.00");

  unsigned long runMillis = millis();
  unsigned long allSeconds = millis() / 1000;
  int runHours = allSeconds / 3600;
  int secsRemaining = allSeconds % 3600;
  int runMinutes = secsRemaining / 60;
  int runSeconds = secsRemaining % 60;

  char buf[21];
  sprintf(buf, "%02d:%02d:%02d", runHours, runMinutes, runSeconds);

  tft.setFont();
  tft.setRotation(3);
  tft.setTextWrap(true);
  tft.setTextSize(1);
  tft.setTextColor(ST7735_WHITE, ST7735_BLACK);

  tft.setCursor(32, 103);  // posicion (x,y)
  tft.println(buf);

  tft.setCursor(86, 103);  // posicion (x,y)
  tft.println("CV | CC");

  tft.setCursor(54, 117);  // posicion (x,y)
  tft.println("DIPS30V5A");
}
