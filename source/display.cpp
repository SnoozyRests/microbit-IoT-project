#include "MicroBit.h"
#include <stdio.h>
MicroBit uBit;
int pincode = 1, accelx = 0, accely = 0, compass = 0, ID = 1, count = 0;
int main(){
  uBit.init();
  if (pincode == 1){
    MicroBitImage smiley("0,255,0,255, 0\n0,255,0,255,0\n0,0,0,0,0\n255,0,0,0,255\n0,255,255,255,0\n");
    uBit.display.scroll(smiley);
    pincode = 2;
  }
  if (pincode == 2){
    uBit.display.scroll("Fans");
    uBit.io.P0.setDigitalValue(1);

    uBit.display.scroll(  uBit.io.P0.getDigitalValue());
    pincode = 3;
  }

  if (pincode == 3){

    if (uBit.accelerometer.getX() > 600){
      accelx ++;
    }
    if (uBit.accelerometer.getY() > 600){
      accely ++;
    }
    if (uBit.accelerometer.getX() < 1200){
      accelx --;
    }
    if (uBit.accelerometer.getY() < 1200){
      accely --;
    }
    uBit.display.scroll("Accell");
    uBit.display.image.clear();
    uBit.display.image.setPixelValue(accelx,accely,255);

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


/*
io(MICROBIT_ID_IO_P0,MICROBIT_ID_IO_P1,MICROBIT_ID_IO_P2,
       MICROBIT_ID_IO_P3,MICROBIT_ID_IO_P4,MICROBIT_ID_IO_P5,
       MICROBIT_ID_IO_P6,MICROBIT_ID_IO_P7,MICROBIT_ID_IO_P8,
       MICROBIT_ID_IO_P9,MICROBIT_ID_IO_P10,MICROBIT_ID_IO_P11,
       MICROBIT_ID_IO_P12,MICROBIT_ID_IO_P13,MICROBIT_ID_IO_P14,
       MICROBIT_ID_IO_P15,MICROBIT_ID_IO_P16,MICROBIT_ID_IO_P19,
       MICROBIT_ID_IO_P20),
*/
