/*
  An example showing rainbow colours on a 160x128 TFT LCD screen
  and to show a basic example of font use.

  This example plots the text in a sprite then pushes the sprite to the
  TFT screen.
  
  Make sure all the display driver and pin connections are correct by
  editing the User_Setup.h file in the TFT_eSPI library folder.

  Note that yield() or delay(0) must be called in long duration for/while
  loops to stop the ESP8266 watchdog triggering.

  #########################################################################
  ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
  #########################################################################
*/

#define IWIDTH 240
#define IHEIGHT 135

#include <TFT_eSPI.h> // Graphics and font library
#include <SPI.h>

#include <stdlib.h> //for rand

TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h

TFT_eSprite img = TFT_eSprite(&tft);

TFT_eSprite stext2 = TFT_eSprite(&tft); // Sprite object stext2

TFT_eSprite heart = TFT_eSprite(&tft); // Sprite object 

TFT_eSprite tinyheart = TFT_eSprite(&tft);


unsigned long targetTime = 0;
byte red = 31;
byte green = 0;
byte blue = 0;
byte state = 0;
unsigned int colour = red << 11;
int tcount = 300;//1000;


int firstlyricplace[] = {45,13,69,93,117,29,77,5,61};
//int lyricplace[] = {5,13,29,45,61,69,77,93,117};

const char *firstlyrics[] = {
  "It's you, it's you, it's all for you\n  everything I do ",//45
  "If you hold me without hurting me,\n  you'd be the first that ever did",//13
  "You're beautiful and I'm insane",//69
  "I've got things to do like nothing at   all "
  "I wanna do them with you "
  "Do you \n wanna do them with me? ",//93
  "All the pretty stars, shine for you my love",//117
  "Everybody told me love was blind Then   I saw your face and you blew my mind ",//29
  "You fit me better than my favorite\n  sweater",//77
  "Heaven is a place on earth with you", //5
  "I fall to pieces when I'm with you"//61
};

//int seclyricplace[] = {5,21,37,53,69,85,101,117};

int seclyricplace[] = {37,101,85,5,117,21,69,53};


const char *seclyrics[] = {
  "No one compares to you, I'm scared that you won't be waiting on the other side", //37
  "Why wait for the best when I\n could have you?", //101
  "There's things I wanna say to you\n but I'll just let you live", //85
  "When's it gonna be my turn? \n Don't forget me", //5
  "It hurts to love you, but I still love  you  it's just the way I feel.",//117
  "Isn't strange that you're not here\n with me", //21
  "Shared my body & my mind with you,\n that's all over now", //69
  "What's the worst that can happen to\n a girl who's already hurt?" //53
};

int rainbow[] = {

  
  0xD000,
 0xFA60, //orange?
 0xFF09, //yellow
 0x4CE0, //darker green
 0x04E5,//other green
 0x0400,//new
  0x4EBD, // lgith blu
  0x4D5D, //one or othdf
  0x543F,// blye
  0x6A9F, //..purplke
  0x941F,
  0x519F,
  0xC2BF,
  0xA27A,
};


void drawPinkHeart(int x, int y,int s,int xi, int yi){
  heart.fillSprite(TFT_TRANSPARENT);
  heart.fillCircle(80 +x, 60+y, 30, 0xFAF7);
  heart.fillCircle(120+x, 60+y, 30, 0xFAF7);
  heart.fillTriangle(57+x, 80+y, 100+x, 120+y, 143+x, 80+y, 0xFAF7);  
  //maybe put transparent hole in it 
  heart.pushToSprite(&img,xi,yi,TFT_TRANSPARENT);
}


void drawRedHeart(int x, int y,int xi, int yi, bool big) {
  heart.fillSprite(TFT_TRANSPARENT);
  if (big){
    heart.fillCircle(75 +x, 60+y, 40, TFT_RED);
    heart.fillCircle(125+x, 60+y, 40, TFT_RED);
    heart.fillTriangle(40+x, 80+y, 100+x, 135+y, 160+x, 80+y, TFT_RED);
  }else{
    heart.fillCircle(80 +x, 60+y, 30, TFT_RED);
    heart.fillCircle(120+x, 60+y, 30, TFT_RED);
    heart.fillTriangle(57+x, 80+y, 100+x, 120+y, 143+x, 80+y, TFT_RED);    
  }
  heart.pushToSprite(&img,xi+10,yi-10,TFT_TRANSPARENT);
}

void heartBeat(int pace){
 //   img.fillSprite(TFT_BLACK);
    drawRedHeart(0,0,0,0,0);
    img.pushSprite(0,0);
    delay(pace);
 //   img.fillSprite(TFT_BLACK);
    drawRedHeart(0,0,0,0,1);
    img.pushSprite(0,0);
    delay(pace);
}

void drawTinyHeart(int x, int y, int color){
  tinyheart.setColorDepth(8);
  tinyheart.createSprite(35, 30);
  tinyheart.fillSprite(TFT_TRANSPARENT);

  tinyheart.fillCircle(18, 10, 5, color);
  tinyheart.fillCircle(27, 10, 5, color);
  tinyheart.fillTriangle(15, 13, 23, 23, 30, 13, color);

  tinyheart.pushSprite(x,y,TFT_TRANSPARENT);
  // Delete it to free memory
  tinyheart.deleteSprite();
}


void setup(void) {

  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);

  img.createSprite(IWIDTH, IHEIGHT);
  img.fillSprite(TFT_BLACK);

  targetTime = millis() + 1000;
 
  heart.createSprite(IWIDTH, IHEIGHT);

  tft.fillScreen(TFT_BLACK);

}



void loop() {

  tcount--;
  if (tcount > 900) {

    for (int i = 0; i < 500; i++) // flood screen with hearts
    {
      int x = random(320-80);
      int y = random(240-70);
      int c = random(0x10000); // Random colour
      drawTinyHeart(x, y, c);
      yield(); // Stop watchdog reset
      delay(2);
    }

  } else if (tcount > 300){
    if (targetTime < millis()) {
      targetTime = millis() + 100;

      // Colour changing state machine
      for (int i = 0; i < 240; i++) {
        img.drawFastVLine(i, 0, img.height(), colour);
        switch (state) {
          case 0:
            green += 2;
            if (green == 64) {
              green = 63;
              state = 1;
            }
            break;
          case 1:
            red--;
            if (red == 255) {
              red = 0;
              state = 2;
            }
            break;
          case 2:
            blue ++;
            if (blue == 32) {
              blue = 31;
              state = 3;
            }
            break;
          case 3:
            green -= 2;
            if (green == 255) {
              green = 0;
              state = 4;
            }
            break;
          case 4:
            red ++;
            if (red == 32) {
              red = 31;
              state = 5;
            }
            break;
          case 5:
            blue --;
            if (blue == 255) {
              blue = 0;
              state = 0;
            }
            break;
        }
        colour = red << 11 | green << 5 | blue;
      }

      img.setTextColor(TFT_BLACK); //CHECK IF CAN DO BORDER

      for(size_t i = 0; i < (900-tcount)/20 && i < sizeof(firstlyricplace) / sizeof(int); i++) // slowly print lyrics
      {
        img.setCursor(8,firstlyricplace[i]);
        img.print(firstlyrics[i]);
      }

      int x = random(-50,70);
      int y = random(-15,15);
      drawPinkHeart(0,0,0,x,y);

      img.pushSprite(0, 0);
      
    }

    delay(50);

  } else {

    if (tcount <= 0)
    { 
      // sleep
      tft.fillScreen(TFT_BLACK);
      tcount = 1000;
      //100000
     // esp_sleep_enable_timer_wakeup(100000);
     // esp_deep_sleep_start();
      esp_deep_sleep(100000000);
      ledcSetup(0, 5000, 8); // 0-15, 5000, 8
      ledcAttachPin(TFT_BL, 0); // TFT_BL, 0 - 15
      ledcWrite(0, 255); // 0-15, 0-255 (with 8 bit resolution)


    }else{

      img.fillSprite(TFT_BLACK);
      img.setTextColor(TFT_WHITE);

      //could change section to just use tft
      int ri = 0;
      for(size_t i = 0; i < (300-tcount)/20 && i < sizeof(seclyricplace) / sizeof(int); i++) //slowly print lyrics
      {
        img.setCursor(4,seclyricplace[i]);
        img.setTextColor(rainbow[ri]);
        img.print(seclyrics[i]);
        ri++;
        
      }

      if (tcount <= 110){

        //maybe instead draw line thru heart and spereate
        // for(size_t i = 0; i < 110-tcount; i++){
          //draw lines around 0,0

       // }
        drawRedHeart(0,0,0,110-tcount,0); // move heart down
        img.pushSprite(0,0);//try del
        ledcSetup(0, 5000, 8); // 0-15, 5000, 8
        ledcAttachPin(TFT_BL, 0); // TFT_BL, 0 - 15
        ledcWrite(0, tcount*2); // 0-15, 0-255 (with 8 bit resolution)

        delay(50);
      } else {
        tcount > 150 ? heartBeat(350-tcount) : heartBeat(200); //slow down heart beat
      }

    }

  }

}






