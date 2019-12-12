#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
#include<stdlib.h>
#include <stdint.h>
#include <string.h>

int main (int argc, char *argv []){
  int i, length, maxlength = 127, arraycounter = 0, counter = 0, saltingnumber, letterselect, saltingint;
  char *saltingletters = "abcdefghijklmnopqrstuvwyxz"
                         "ABCDEFGHIJKLMNOPQRSTUVWYXZ"
                         "0123456789";

  char saltletter[] = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
  //char saltletter[128];
  char letter [4];

  float random_letter = 0.0;
  length = 128;

  printf("%i is the length \n", length);
for (i = 0; i < length; i = i + 1){

  random_letter = (62.0 * rand()/(RAND_MAX + 1.0));
  letterselect = (int)random_letter;
  //printf("%f is the random number \n", random_letter);
// printf("%d is the number \n", saltingint);
    char value = saltingletters[letterselect];
  

     //printf("%d is the letter added  \n", value);
    saltletter[i] = value;
      
 printf("%d the count is \n", i);
  printf("%s \n", saltletter);
 
}
}
