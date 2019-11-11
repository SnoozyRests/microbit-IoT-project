#include "MicroBit.h"
#include <stdio.h>

MicroBit uBit;

int main(){
  uBit.init();
  uBit.display.scroll("RECEIVE");
  release_fiber();
}
