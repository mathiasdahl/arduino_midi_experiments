#include <stdio.h>
#include "simulate.c"
#include "simulate_tests.h"

int main (void) {
   test_getArduinoPinForPot();
   test_getMuxPinForPot ();
   return 0;
}

void test_getArduinoPinForPot () {
   printf ("getArduinoPinForPot:\n");
   if (getArduinoPinForPot(1) != ARDUINO_MUX_INPUT_PINS[0]) {
      printf ("  Error 01\n");
      return;
   }
   if (getArduinoPinForPot(8) != ARDUINO_MUX_INPUT_PINS[0]) {
      printf ("  Error 02\n");
      return;
   }
   if (getArduinoPinForPot(9) != ARDUINO_MUX_INPUT_PINS[1]) {
      printf ("  Error 03\n");
      return;
   }
   if (getArduinoPinForPot(16) != ARDUINO_MUX_INPUT_PINS[1]) {
      printf ("  Error 04\n");
      return;
   }
   printf ("  OK\n");
}

void test_getMuxPinForPot () {
   printf ("getMuxPinForPot:\n");
   if (getMuxPinForPot(1) != 0) {
      printf ("  Error 01\n");
      return;
   }
   if (getMuxPinForPot(2) != 1) {
      printf ("  Error 02\n");
      return;
   }
   if (getMuxPinForPot(3) != 2) {
      printf ("  Error 03\n");
      return;
   }
   if (getMuxPinForPot(8) != 7) {
      printf ("  Error 04\n");
      return;
   }
   if (getMuxPinForPot(9) != 0) {
      printf ("  Error 05\n");
      return;
   }
   if (getMuxPinForPot(16) != 7) {
      printf ("  Error 06\n");
      return;
   }
   printf ("  OK\n");
}
