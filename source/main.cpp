#include "MicroBit.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Prototyping
MicroBit uBit;
int selectMode();
int rotaryDialer(char *pin);
int saltgen(char *salt, int length);
int createDPK(char *salt);
int sendMode();
int recieveMode();
void onRecv();
char getChar(char msChar);

//Globally utilised variables.
int messageMode = 0; //0 = Saltshaking, 1 = Communicating.
char pin[] = {'0','0','0','0','\0'};
char salt[128];
int recvSaltPos = 0;
char dpk[65];
char pinSalt[132];

//external SHA256 hashing function.
extern void sha256(const void *data, size_t len, char *sha2digest);

/*
  Function: onRecv
  Operation: Processes the incoming radio communication.
  Inputs: MicrobitEvent - the radio input.
  Outputs: WIP
  Notes: This function must occur at the beginning of the program or it will
          cause errors, it may be that it simply needs to occur before the
          function that invokes it, prototyping doesnt count, further testing
          needed.
*/
void onRecv(MicroBitEvent){
    ManagedString s = uBit.radio.datagram.recv();
    //uBit.display.print(rb);
    if(s == "ENDSALT"){
      messageMode = 1;
      createDPK(salt);
      uBit.display.scroll("Message Mode");
    }

    if(messageMode == 0){ //Saltshaking
      salt[recvSaltPos] = getChar(s.charAt(0));
      uBit.display.print(salt[recvSaltPos]);
      //salt[recvSaltPos] = s;
      recvSaltPos++;
    }

    /*
    if(recvSaltPos == 128){
      messageMode = 1;
      //salt[128] = '\0';

      uBit.display.scroll("Message Mode");
    }
    */

    if(messageMode == 1){ //Communicating
      if(s == "comm1"){
        uBit.display.scroll(pin);
        uBit.sleep(300);
        uBit.display.scroll(salt);
        uBit.sleep(300);
      }
      if(s == "comm2"){
        uBit.display.scroll(dpk);
        uBit.sleep(300);
      }
    }
}

/*
  Function: main
  Operation: Primary runtime, initialises mode, gets the pin input, acesses mode.
  Inputs: N/A
  Outputs: N/A
  Notes: N/A
*/
int main(){
    uBit.init();
    int mode = selectMode();
    rotaryDialer(pin);
    uBit.display.scroll(pin);
    if(mode == 1){
      sendMode();
    }else if(mode == 2){
      recieveMode();
    }
    //uBit.display.scroll(dpk);
    release_fiber();
}

/*
  Function: sendMode
  Operation: Controls the sender functions for the system.
  Inputs: N/A
  Outputs: Sucess value.
  Notes:
*/
int sendMode(){
    saltgen(salt, 128);
    createDPK(salt);
    uBit.radio.enable();
    ManagedString s;

    while(messageMode == 0){
      if(uBit.buttonA.isPressed()){
        for(int i = 0; i < 128; i++){
            s = salt[i];
            uBit.radio.datagram.send(s);
            uBit.display.print(s);
            uBit.sleep(100);
        }
        uBit.radio.datagram.send("ENDSALT");
        messageMode = 1;
        //uBit.display.scroll(dpk);
      }
    }
    uBit.sleep(100);
    uBit.display.scroll("Message Mode");
    while(messageMode == 1){
      if(uBit.buttonA.isPressed()){
        uBit.radio.datagram.send("comm1");
        uBit.display.scroll(pin);
        uBit.sleep(300);
        uBit.display.scroll(salt);
        uBit.sleep(300);
      } else if(uBit.buttonB.isPressed()){
        uBit.radio.datagram.send("comm2");
        uBit.display.scroll(dpk);
        uBit.sleep(300);
      }
    }

    return 0;
}


/*
  Function: recieveMode
  Operation: Handles the recieve radio functionality.
  Inputs: N/A
  Outputs: Success Value.
  Notes: Most recieve functionality takes place in onRecv, this handles the
         recieve event.
*/
int recieveMode(){
    uBit.messageBus.listen(MICROBIT_ID_RADIO, MICROBIT_RADIO_EVT_DATAGRAM, onRecv);
    uBit.radio.enable();

    while(true){
      uBit.sleep(1000);
    }
    return 0;
}

/*
  Function: selectMode
  Operation: Handles the mode select for the two different functionalities.
  Input: N/A
  Outputs: 1 = send
           2 = recieve
           0 = error (in reality this should never occur.)
  Notes: N/A
*/
int selectMode(){
    //uBit.display.scroll("< SEND || > RECIEVE");
    while(true){
      if(uBit.buttonA.isPressed()){
        return 1;
      } else if(uBit.buttonB.isPressed()){
        return 2;
      }
    }
    return 0;
}

/*
  Function: rotaryDialer
  Operation: Pin input
  Inputs: char *pin - pointer to pin variable.
  Outputs: Sucess value.
  Notes: uBit.sleep() is absolutely vital to make this work, having the value
         too low means the buttons create multiple inputs, and having it too
         high gives the impression of lag, perhaps further testing is required.
*/
int rotaryDialer(char *pin){
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

char getChar(char msChar){
    char *saltingletters = "abcdefghijklmnopqrstuvwyxz"
                            "ABCDEFGHIJKLMNOPQRSTUVWYXZ"
                            "0123456789";
    for(int i = 0; i < sizeof(saltingletters); i++){
      if(saltingletters[i] == msChar){
        return saltingletters[i];
      }
    }
}
/*
  Function: saltgen
  Operation: generates a variable length salt.
  Input: char *salt - pointer to variable where the salt should be stored.
         int length - length of the desired salt.
  Output: Sucess value.
  Notes: There are no bounds checkings, if your array is smaller than the length
        you pass it will OOB.
*/
int saltgen(char *salt, int length){
    char *saltingletters = "abcdefghijklmnopqrstuvwyxz"
                            "ABCDEFGHIJKLMNOPQRSTUVWYXZ"
                            "0123456789";
    //ManagedString s;
    for (int i = 0; i < length; i = i + 1){
      //s = saltingletters[(int)(62.0 * rand()/(RAND_MAX + 1.0))];
      //salt[i] = s.charAt(0);
      salt[i] = saltingletters[(int)(62.0 * rand()/(RAND_MAX + 1.0))];
    }

    //salt[128] = '\0';
    return 0;
}
/*
  Function: createDPK
  Operation: Handles the construction of the DPK. Merges the pin and salt values
             and the hashes them into SHA256.
  Input: char *salt - pointer to variable containing the salt.
  Output: Sucess value.
  Notes: N/A
*/
int createDPK(char *salt){

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
