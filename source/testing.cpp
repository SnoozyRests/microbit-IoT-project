#include "MicroBit.h"
#include <stdio.h>
MicroBit uBit;
int pincode = 4, accelx = 0, accely = 0;
int main(){
  uBit.init();
  if (pincode = 1){
    MicroBitImage smiley("0,255,0,255, 0\n0,255,0,255,0\n0,0,0,0,0\n255,0,0,0,255\n0,255,255,255,0\n");
    uBit.display.scroll(smiley);
    pincode = 2;
  }
  if (pincode = 2){
    uBit.display.scroll("Lights");
  }
  if (pincode = 3){

    if (uBit.accelerometer.getX() > 600){
      accelx ++;
    }
    uBit.display.scroll("Fans");
  }
  if (pincode = 4){
    uBit.display.scroll("Light Meter");
    if uBit.light() > 512 {
      uBit.display.scroll("Light");
    }else{
      uBit.display.scroll("Dark");
    }  }

}
