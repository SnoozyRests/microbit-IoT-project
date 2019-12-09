#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
#include<stdlib.h>
#include <stdint.h>
#include <string.h>

int main (int argc, char *argv []){
  int i, length, maxlength = 128, arraycounter = 0, counter = 0, saltingnumber, letter[1], saltingint;
  char *saltingletters = "abcdefghijklmnopqrstuvwyxzABCDEFGHIJKLMNOQRSTUVWYXZ0123456789";
  char saltletter[128];
//  char saltarray[128];
  float random_letter = 0.0;
  if (argc < 1){
    printf("%s below 2 \n", argv[0] );
    exit(1);
  }
  length = atoi(argv[1]);
  if (length > maxlength){
    length = 128;
  }
  if (length < maxlength){
    length = 128;
  }

  printf("%i is the length \n", length);
for (i = 0; i < length; i = i + 1){
  random_letter = (62.0 * rand()/(RAND_MAX + 6.2));
    letter[0] = random_letter;
    saltingint = letter[0];
  *(saltletter+counter) = saltingletters[saltingint];
  printf("%i \n", counter);
  counter++;

  //if (counter == 128){
  printf("%s salt \n", saltletter);
//  }
}
}
