#include "main.hpp"
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

  if(state == 2){
    recvCommPos = 0;
    state = 1;
  }

  //Once sender has finished saltshaking its transmits "ENDSALT" to notify.
  if(s == "ENDSALT"){
    createDPK(salt);
    hashComms();
    state = 2;
    recvCommPos = 0;
    uBit.display.scroll(state);
  }
  if(s == "ENDCOM"){
    if(strcmp(recvComm, comm1Hash) == 0){
      uBit.display.scroll("COMM1");
    } else if(strcmp(recvComm, comm2Hash) == 0){
      uBit.display.scroll("COMM2");
    } else if(strcmp(recvComm, comm3Hash) == 0){
      uBit.display.scroll("COMM3");
    } else if(strcmp(recvComm, comm4Hash) == 0){
      uBit.display.scroll("COMM4");
    }
    else{
      uBit.display.scroll(recvComm);
    }
    state = 2;
  }

  //Message mode 0 = saltshaking, characters are recieved and stored, utilised
  // once "ENDSALT" is invoked.
  if(state == 0){
    salt[recvSaltPos] = getChar(s.charAt(0));
    uBit.display.print(salt[recvSaltPos]);
    recvSaltPos++;
  }

  //To be reworked.
  if(state == 1){
    recvComm[recvCommPos] = getChar(s.charAt(0));
    uBit.display.print(recvComm[recvCommPos]);
    recvCommPos++;
  /*
    if(s == "comm1"){
      //uBit.display.scroll(pin);
      //uBit.sleep(300);
      //uBit.display.scroll(salt);
      //uBit.sleep(300);
      uBit.display.scroll(comm3Hash);
    } else if(s == "comm2"){
      //uBit.display.scroll(dpk);
      uBit.display.scroll(recvComm);
      uBit.sleep(300);
    } else if(s == "comm3"){
      uBit.display.scroll(s);
      uBit.sleep(300);
    }else if (s == "comm4"){
      uBit.display.scroll(s);
      uBit.sleep(300);
    }*/
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

  //get desired mode.
  int mode = selectMode();

  //get pin
  rotaryDialer(pin);
  uBit.display.scroll(pin);

  //set mode.
  if(mode == 1){
    sendMode();
  }else if(mode == 2){
    recieveMode();
  }

  //Clear uBit threads, typically never reached in this case.
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
  //DPK generation calls.
  saltgen(salt, 128);
  createDPK(salt);
  hashComms();

  //enable Microbit radio and its requirements.
  uBit.radio.enable();
  ManagedString s;

  //perform saltshaking.
  while(state == 0){
    if(uBit.buttonA.isPressed()){
      for(int i = 0; i < SALTSIZE / 4; i++){
          s = salt[i];
          uBit.radio.datagram.send(s);
          uBit.display.print(s);
          uBit.sleep(100);
      }

      //signal end of Saltshaking, transition to messageMode.
      uBit.radio.datagram.send("ENDSALT");
      state = 1;
    }
  }

  //Sleep for soft barrier, signal message mode.
  uBit.sleep(100);
  uBit.display.scroll("Message Mode");

  //Perform message mode, TO BE EXPANDED.
  while(state == 1){
    if(uBit.buttonA.isPressed()){
      for(int i = 0; i < 64; i++){
          s = comm1Hash[i];
          uBit.radio.datagram.send(s);
          uBit.display.print(s);
          uBit.sleep(100);
      }
      uBit.radio.datagram.send("ENDCOM");
    } else if(uBit.buttonB.isPressed()){
      for(int i = 0; i < 64; i++){
          s = comm2Hash[i];
          uBit.radio.datagram.send(s);
          uBit.display.print(s);
          uBit.sleep(100);
      }
      uBit.radio.datagram.send("ENDCOM");
    }
  }

  //Never reached.
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
  //enable Microbit radio reciever, designate processing function.
  uBit.messageBus.listen(MICROBIT_ID_RADIO, MICROBIT_RADIO_EVT_DATAGRAM, onRecv);
  uBit.radio.enable();

  //await recieve.
  while(true){
    uBit.sleep(1000);
  }

  //never reached.
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

  //await input.
  while(true){
    if(uBit.buttonA.isPressed()){
      return 1;
    }else if(uBit.buttonB.isPressed()){
      return 2;
    }
  }

  //never reached.
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
  //runtime critical variables.
  char no[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  int ringPos = 0, pinPos = 0;

  //define Microbit button events, prevents double presses.
  uBit.buttonB.setEventConfiguration(MICROBIT_BUTTON_SIMPLE_EVENTS);
  uBit.sleep(300);

  //Perform rotaryDialer.
  while(true){
    uBit.display.print(no[ringPos]);

    //LOCK
    if(uBit.buttonA.isPressed()){
      pin[pinPos] = no[ringPos];
      if(pinPos == 3){
        return 0;
      }else{
        pinPos++;
      }
      uBit.sleep(300);
    }

    //ROTATE
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

  //Never reached.
  return 1;
}

/*
  Function: getChar
  Operation: Converts the datagram character to a char character.
  Input: msChar - the character recieved via radio communication.
  Output: lookup[n] - the matching char equivilent character.
  Notes: The character recieved by the microbit is functionally the same as
          the typical C character but when exposed to hashing for encryption it
          for some reason yields a different result to the sender, it could be
          that the byte value of a character in ManagedString differs to that of
          char encoding.
*/
char getChar(char msChar){
  //All legal characters.
  char *lookup = "abcdefghijklmnopqrstuvwyxz"
                  "ABCDEFGHIJKLMNOPQRSTUVWYXZ"
                  "0123456789";

  //Perform lookup.
  for(int i = 0; i < sizeof(lookup); i++){
    if(lookup[i] == msChar){
      return lookup[i];
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
  //Salt compliant characters.
  char *saltingletters = "abcdefghijklmnopqrstuvwyxz"
                          "ABCDEFGHIJKLMNOPQRSTUVWYXZ"
                          "0123456789";

  //Generate random number between 0 and 62, assign character based on output.
  for (int i = 0; i < length / 4; i = i + 1){
    salt[i] = saltingletters[(int)(62.0 * rand()/(RAND_MAX + 1.0))];
  }

  //return to calling function.
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
  //insert pin.
  pinSalt[0] = pin[0];
  pinSalt[1] = pin[1];
  pinSalt[2] = pin[2];
  pinSalt[3] = pin[3];

  //insert salt.
  int j = 0;
  for(int i = 4; i <= SALTSIZE / 4; i++){
    pinSalt[i] = salt[j];
    j++;
  }

  //hash
  sha256(pinSalt, sizeof(pinSalt), dpk);

  //return to calling function.
  return 0;
}

int hashComms(){
  char temp[69];

  temp[0] = comm1Pin[0];
  temp[1] = comm1Pin[1];
  temp[2] = comm1Pin[2];
  temp[3] = comm1Pin[3];

  int j = 0;
  for(int i = 4; i <= 69; i++){
    temp[i] = dpk[j];
    j++;
  }
  sha256(temp, sizeof(pinSalt), comm1Hash);

  temp[0] = comm2Pin[0];
  temp[1] = comm2Pin[1];
  temp[2] = comm2Pin[2];
  temp[3] = comm2Pin[3];

  sha256(temp, sizeof(pinSalt), comm2Hash);

  temp[0] = comm3Pin[0];
  temp[1] = comm3Pin[1];
  temp[2] = comm3Pin[2];
  temp[3] = comm3Pin[3];

  sha256(temp, sizeof(pinSalt), comm3Hash);

  temp[0] = comm4Pin[0];
  temp[1] = comm4Pin[1];
  temp[2] = comm4Pin[2];
  temp[3] = comm4Pin[3];

  sha256(temp, sizeof(pinSalt), comm4Hash);

  return 0;
}
