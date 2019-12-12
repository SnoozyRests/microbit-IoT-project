#include "MicroBit.h"
#include <stdio.h>

MicroBit uBit;
int selectMode();
int ringdialer(char *pin);
int initCommands(char *pin);
char pin[] = {'0','0','0','0','\0'};

int main(){
  uBit.init();
  //int mode = selectMode();
  //uBit.display.scroll(mode);
  ringdialer(pin);
  release_fiber();
}

int selectMode(){
  uBit.display.scroll("< SEND || > RECIEVE");
  while(true){
    if(uBit.buttonA.isPressed()){
      return 1;
    } else if(uBit.buttonB.isPressed()){
      return 2;
    }
  }
  return 0;
}

int ringdialer(char *pin){
    char no[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int ringPos = 0, pinPos = 0;
    uBit.buttonB.setEventConfiguration(MICROBIT_BUTTON_SIMPLE_EVENTS);
    while(true){
      uBit.display.print(no[ringPos]);
      if(uBit.buttonA.isPressed()){
        pin[pinPos] = no[ringPos];
        if(pinPos == 3){
          return 0;
        }else{
          pinPos++;
        }
        uBit.sleep(200);
      }
      if(uBit.buttonB.isPressed()){
        if(ringPos == 9){
          ringPos = 0;
          uBit.sleep(200);
        }else{
          ringPos++;
          uBit.sleep(200);
        }
      }
    }
    return 1;
}

int initCommands(char *pin){

}
