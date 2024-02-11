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

#include <stdlib.h>

TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h

TFT_eSprite img = TFT_eSprite(&tft);

TFT_eSprite stext2 = TFT_eSprite(&tft); // Sprite object stext2

TFT_eSprite heart = TFT_eSprite(&tft); // Sprite object 

unsigned long targetTime = 0;
byte red = 31;
byte green = 0;
byte blue = 0;
byte state = 0;
unsigned int colour = red << 11;
int tcount = 0;


int lyricplace[] = {45,13,69,93,117,29,77,5,61};
//int lyricplace[] = {5,13,29,45,61,69,77,93,117};



const char *lyrics[] = {
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


void drawPinkHeart(int x, int y,int s,int xi, int yi){
  heart.fillSprite(TFT_TRANSPARENT);
  heart.fillCircle(80 +x, 60+y, 30, TFT_PINK);
  heart.fillCircle(120+x, 60+y, 30, TFT_PINK);
  heart.fillTriangle(57+x, 80+y, 100+x, 120+y, 143+x, 80+y, TFT_PINK);   
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
    img.fillSprite(TFT_BLACK);
    drawRedHeart(0,0,0,0,0);
    img.pushSprite(0,0);
    delay(pace);
    img.fillSprite(TFT_BLACK);
    drawRedHeart(0,0,0,0,1);
    img.pushSprite(0,0);
    delay(pace);
}



void setup(void) {
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);

  img.createSprite(IWIDTH, IHEIGHT);
  img.fillSprite(TFT_BLACK);

  targetTime = millis() + 1000;

 // Create a sprite for Hello World
  stext2.setColorDepth(8);
  stext2.createSprite(180, 16);
  stext2.fillSprite(TFT_BLACK);
  stext2.setScrollRect(0, 0, 180, 16, TFT_BLACK); // Scroll the "Hello" in the first 40 pixels
  stext2.setTextColor(TFT_LIGHTGREY); // White text, no background

  heart.createSprite(240, 135);


}



void loop() {

  tcount--;

  
  if (tcount > 500){
    if (targetTime < millis()) {
      targetTime = millis() + 100;//10000;

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

      // The standard ADAFruit font still works as before
     // img.setTextColor(TFT_BLACK);
      
      img.setTextColor(TFT_WHITE); // Do not plot the background colour //maybe make black

      for(size_t i = 0; i < (1000-tcount)/20 && i < sizeof(lyrics) / sizeof(int); i++)
      {
        img.setCursor(8,lyricplace[i]);
        img.print(lyrics[i]);
      }

      

      drawPinkHeart(0,0,0,rand()%80-50,rand()%100-50);
      img.pushSprite(0, 0);
      
      
    }

    delay(100);


  } else {



   // img.pushSprite(0,0);


    

  //  stext2.pushSprite(0, 70);


  //  stext2.scroll(1);     // scroll stext 1 pixel right, up/down default is 0
  //  img.fillSprite(TFT_BLACK);

    if (tcount <= 0)
    { 
      // sleep
      tcount = 1000;
    }else{
      if (tcount <= 110){
        drawRedHeart(0,0,0,110-tcount,0); // BOOM BOOM add settings to switch between two diff sizes
        img.pushSprite(0,0);
      } else {
        tcount > 250 ? heartBeat(550-tcount) : heartBeat(300);
      }
    }
//    else if (tcount % 100 == 0){
      // If we have scrolled 100 pixels the redraw text
   //   stext2.drawString("Hi from Chloe", 6, 0, 2); // draw at 6,0 in sprite, font 2
//    }

   // heart.scroll(1);


    

    
    



  }

}






