#include <stdio.h>
#include <unistd.h>
#include "simulate.h"

const int POTS = 16;
const int MULTIPLEXERS = 2;
const int POTS_PER_MUX = 8;
const int ARDUINO_MUX_INPUT_PINS[2] = {15, 16};

int analogRead(int pin) {
   return 0;
}

void digitalWrite(int pin, int value) {
   printf ("digitalWrite: set %d to %s\n", pin, value < 1 ? "LOW" : "HIGH");
}

void setup() {
   printf ("setup()\n");
}

void loop () {
   printf ("loop()\n");
   readPots();
   sleep(1);
}

int getArduinoPinForPot(int potNo) {
   int divResult = (potNo - 1) / POTS_PER_MUX;
   int muxNo = divResult;
   return ARDUINO_MUX_INPUT_PINS[muxNo];
}

int readPot(int potNo) {
   analogRead(getArduinoPinForPot(potNo));
   return 0;
}

void readPots () {
   printf ("readPots()\n");
   int i;
   for (i = 0; i < POTS; i++) {
      printf ("  read pot %d\n", i);
   }
}
