#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int saltgen(char *salt, int length){
  char *saltingletters = "abcdefghijklmnopqrstuvwyxz"
                         "ABCDEFGHIJKLMNOPQRSTUVWYXZ"
                         "0123456789";

  //char saltletter[128];
  //char letter [4];
  //length = 128;

  //printf("%i is the length \n", length);
  for (int i = 0; i < length; i = i + 1){
    salt[i] = saltingletters[(int)(62.0 * rand()/(RAND_MAX + 1.0))];
  }

  salt[128] = '\0';
  //printf("%s\n", saltletter);
  return 0;
}
