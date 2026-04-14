//#define USE_LittleFS
 #include <FS.h>
#ifdef USE_LittleFS
  #define SPIFFS LITTLEFS
  #include <LITTLEFS.h> 
#else
  #include <SPIFFS.h>
#endif
#include <TFT_eSPI.h> // Hardware-specific library
#include <TFT_eFEX.h> // Hardware-specific library
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library
TFT_eFEX  fex = TFT_eFEX(&tft);    // Create TFT_eFEX object "fex" with pointer to "tft" object


int tftHeight;
int tftWidth;
int staticMenuWidth = 75; //this is how much space we need for the static menu
float percContentMenuWidth = 0.85;

#define st_BLACK 0x0000
#define st_BLUE 0x9CD9 //http://www.barth-dev.de/online/rgb565-color-picker/
#define st_ORANGE 0xFCC0
#define st_LTPURPLE 0xCCD9
#define st_BLUE 0x9CD9
#define st_RED 0xCB2C
#define st_TAN 0xFE73
#define st_PURPLE 0x9CDF
#define st_PEACH 0xFCCC
#define st_HTPINK 0xCB33
#define st_WHITE 0xFFFF
#define st_OFFWHITE 0xEF7D
#define st_DKGRAY 0x8410
#define st_LTGRAY 0xA514
#define st_LTBLUE 0xC7BF
#define st_NTBLUE 0x12DD
#define st_GRAPHITE 0x31A6
#define st_YELLOW 0xFFF0
#define st_GREEN  0xAF72 //0x07F0

#define STFONT40 "StarTrek40"
#define STFONT38 "StarTrek38"
#define STFONT28 "StarTrek28"
#define STFONT24 "StarTrek24"
#define STFONT18 "StarTrek18"
#define STFONT12 "StarTrek12"

TFT_eSprite spr = TFT_eSprite(&tft);

void setup(void) {
  if (!SPIFFS.begin()) {
    Serial.println("SPIFFS initialisation failed!");
    while (1) yield(); // Stay here twiddling thumbs waiting
  }
  Serial.println("\r\nSPIFFS initialised.");
  tft.init();
  //TFT------------------------
  //tft.begin();          // Initialize screen
  tft.fillScreen(st_BLACK);
  tft.setRotation(1);
  tftHeight = tft.height();
  tftWidth = tft.width();
}

void loop() {
  //fex.drawJpeg("/Menue.jpg", 0,0);
  fex.drawBmp("/LCARS.bmp", 0,0);
  tft.loadFont(STFONT28);
  delay(1000);
  tft.drawString("Hallo Marwin", 10, 30);
  delay(5000);
  tft.fillScreen(st_BLACK);
  fex.drawBmp("/body.bmp", 0,0);
  //makeButton("Start", 10, 10);
  delay(5000);
}



