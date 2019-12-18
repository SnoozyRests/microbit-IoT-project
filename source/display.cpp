#include "MicroBit.h"
#include <stdio.h>
MicroBit uBit;
int pincode = 1, accelx = 0, accely = 0, compass = 0, ID = 1;
int main(){
  uBit.init();
  if (pincode == 1){
    MicroBitImage smiley("0,255,0,255, 0\n0,255,0,255,0\n0,0,0,0,0\n255,0,0,0,255\n0,255,255,255,0\n");
    uBit.display.scroll(smiley);
    pincode = 2;
  }
  if (pincode == 2){
    uBit.display.scroll("Fans");
    pincode = 3;
  }

  if (pincode == 3){

    if (uBit.accelerometer.getX() > 600){
      accelx ++;
    }
    if (uBit.accelerometer.getY() > 600){
      accely ++;
    }
    uBit.display.scroll("Lights");

    pincode = 4;
  }
 if (pincode == 4){
   uBit.compass.calibrate();
    if (uBit.compass.heading() < 90 && uBit.compass.heading() >= 0 ) {
      uBit.display.scroll("North");
    }if (uBit.compass.heading() < 180 && uBit.compass.heading() >= 90 ){
      uBit.display.scroll("East");
    }if (uBit.compass.heading() < 270 && uBit.compass.heading() >= 180){
      uBit.display.scroll("South");
    }if (uBit.compass.heading() < 360 && uBit.compass.heading() >= 270){
      uBit.display.scroll("West");
    }
    //else{
      //uBit.display.scroll("Compass Failure");
   //}
  }

}
