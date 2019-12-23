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
int state = 0; //0 = Saltshaking, 1 = Communicating.
char pin[] = {'0','0','0','0','\0'};
char salt[128];
int recvSaltPos = 0;
char dpk[65];
char pinSalt[132];

//external SHA256 hashing function.
extern void sha256(const void *data, size_t len, char *sha2digest);
