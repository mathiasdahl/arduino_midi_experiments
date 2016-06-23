#include <stdio.h>
#include "simulate.c"
#include "simulate_tests.h"

int main (void) {
   test3();
   test4 ();
   return 0;
}

void test3 () {
   printf ("test3\n");
   if (getArduinoPinForPot(1) != ARDUINO_MUX_INPUT_PINS[0])
      printf ("  Error 01\n");
   if (getArduinoPinForPot(8) != ARDUINO_MUX_INPUT_PINS[0])
      printf ("  Error 02\n");
   if (getArduinoPinForPot(9) != ARDUINO_MUX_INPUT_PINS[1])
      printf ("  Error 03\n");
   if (getArduinoPinForPot(16) != ARDUINO_MUX_INPUT_PINS[1])
      printf ("  Error 04\n");
}

void test4 () {
   printf ("test4\n");
   if (getMuxPinForPot(1) != 0)
      printf ("  Error 01\n");
}
