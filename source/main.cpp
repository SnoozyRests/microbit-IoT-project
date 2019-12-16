#include "MicroBit.h"
#include <stdio.h>
#include "salting.c"

MicroBit uBit;
int selectMode();
int ringdialer(char *pin);
int createDPK(char *salt);
int sendMode();
int recieveMode();
char salt[128];
void onRecv();

char pin[] = {'0','0','0','0','\0'};
char dpk[65];

extern void sha256(const void *data, size_t len, char *sha2digest);

void onRecv(MicroBitEvent){
    PacketBuffer rb = uBit.radio.datagram.recv();
    uBit.display.print(rb);
}

int main(){
  uBit.init();
  int mode = selectMode();
  ringdialer(pin);
  uBit.display.scroll(pin);
  if(mode == 1){
    sendMode();
  }else if(mode == 2){
    recieveMode();
  }
  //uBit.display.scroll(dpk);
  release_fiber();
}

int sendMode(){
    saltgen(salt, 128);
    createDPK(salt);
    uBit.radio.enable();
    ManagedString s;
    s = salt[0];

    while(true){
      if(uBit.buttonA.isPressed()){
        for(int i = 0; i < sizeof(salt); i++){
            s = salt[i];
            uBit.radio.datagram.send(s);
            uBit.display.print(s);
            uBit.sleep(1000);
        }
      } else if(uBit.buttonB.isPressed()){
        uBit.radio.datagram.send("button b");
      }
      uBit.sleep(100);
    }
    return 0;
}

int recieveMode(){
    uBit.messageBus.listen(MICROBIT_ID_RADIO, MICROBIT_RADIO_EVT_DATAGRAM, onRecv);
    uBit.radio.enable();

    while(true){
      uBit.sleep(1000);
    }
    return 0;
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
    uBit.sleep(300);
    while(true){
      uBit.display.print(no[ringPos]);
      if(uBit.buttonA.isPressed()){
        pin[pinPos] = no[ringPos];
        if(pinPos == 3){
          return 0;
        }else{
          pinPos++;
        }
        uBit.sleep(300);
      }
      if(uBit.buttonB.isPressed()){
        if(ringPos == 9){
          ringPos = 0;
          uBit.sleep(300);
        }else{
          ringPos++;
          uBit.sleep(300);
        }
      }
    }
    return 1;
}

int createDPK(char *salt){
  char pinSalt[132];
  pinSalt[0] = pin[0];
  pinSalt[1] = pin[1];
  pinSalt[2] = pin[2];
  pinSalt[3] = pin[3];

  int j = 0;
  for(int i = 4; i <= 128; i++){
    pinSalt[i] = salt[j];
    j++;
  }

  sha256(pinSalt, sizeof(pinSalt), dpk);
  return 0;
}
