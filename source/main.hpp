#include "MicroBit.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/*
  Only change after some careful consideration, drastic changes can need fine
  tuning.
*/
#define SALTSIZE 128
#define KEYSIZE 256
#define DEBUG 0 //0 - Normal command operation, 1 - Debug command passing

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
int hashComms();
void sendCommand(int comm);

void accel();
void compass();
void fans();
int pixel_from_g(int val);

//variable size constants.
const int saltArraySize = SALTSIZE / 4;
const int pinSaltArraySize = saltArraySize + 4;

//Globally utilised variables.
int state = 0; //0 = Saltshaking, 1 = Communicating, 2 = Lock
char pin[] = {'0','0','0','0','\0'};
char salt[saltArraySize];
int recvSaltPos = 0;
int recvCommPos = 0;
char dpk[65];
char pinSalt[pinSaltArraySize];
char recvComm[65];

//command variables
char comm1Pin[] = {'1','2','3','4'};
char comm2Pin[] = {'2','3','4','5'};
char comm3Pin[] = {'3','4','5','6'};
char comm4Pin[] = {'4','5','6','7'};
char comm1Hash[65], comm2Hash[65], comm3Hash[65], comm4Hash[65];

//external SHA256 hashing function.
extern void sha256(const void *data, size_t len, char *sha2digest);
