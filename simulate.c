#include <stdio.h>
#include <unistd.h>
#include "simulate.h"

typedef enum { false, true } bool;

#define SIMULATE 1
const int POTS = 16;
const int MULTIPLEXERS = 2;
const int POTS_PER_MUX = 8;
const int ARDUINO_MUX_INPUT_PINS[2] = {15, 16};

const int potValues[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

#if SIMULATE

int analogRead (int pin) {
   if (pin == ARDUINO_MUX_INPUT_PINS[0]) {
      return -1;
   } else {
      return 0;
   }
}

void digitalWrite (int pin, int value) {
   printf ("digitalWrite: set %d to %s\n", pin, value < 1 ? "LOW" : "HIGH");
}

int muxCtrlPins[2][3] = {
   {0, 0, 0},
   {0, 0, 0}
};

void setControlPins (int pinValues[]) {
   int i;
   for (i = 0; i < MULTIPLEXERS; i++) {
      muxCtrlPins[i][0] = pinValues[0];
      muxCtrlPins[i][1] = pinValues[1];
      muxCtrlPins[i][2] = pinValues[2];
   }
}

#else

int previousPotReadings[POTS];

void setControlPins (int pinValues[]) {
   int i;
   for (i = 0; i < MULTIPLEXERS; i++) {
      printf ("TODO - set mux control pins\n");
   }
}

#endif

void setup() {
   printf ("setup()\n");
}

void loop () {
   printf ("loop()\n");
   readPots();
   sleep(1);
}

int getMuxForPot(int potNo) {
   int divResult = (potNo - 1) / POTS_PER_MUX;
   int muxNo = divResult;
   return muxNo;
}

int getArduinoPinForPot(int potNo) {
   return ARDUINO_MUX_INPUT_PINS[getMuxForPot(potNo)];
}

int getMuxPinForPot (int potNo) {
   return ((potNo - 1) % POTS_PER_MUX);
}

const int NUMBER_CTRL_PIN_MATRIX[8][3] = {
   {0, 0, 0},
   {1, 0, 0},
   {0, 1, 0},
   {1, 1, 0},
   {0, 0, 1},
   {1, 0, 1},
   {0, 1, 1},
   {1, 1, 1}
};

void getControlPins (int number, int pins[]) {
   pins[0] = NUMBER_CTRL_PIN_MATRIX[number][0];
   pins[1] = NUMBER_CTRL_PIN_MATRIX[number][1];
   pins[2] = NUMBER_CTRL_PIN_MATRIX[number][2];
}

int currentMuxPin = -1;

int readPot (int potNo) {
   int muxPin = getMuxPinForPot (potNo);
   if (muxPin != currentMuxPin) {
      int ctrlPinValues[3];
      getControlPins (muxPin, ctrlPinValues);
      setControlPins (ctrlPinValues);
      currentMuxPin = muxPin;
   }
   int analogPin = getArduinoPinForPot (potNo);
   analogRead (analogPin);
   return -1;
}

void readPots () {
   printf ("readPots()\n");
   int i;
   int potValue;
   for (i = 1; i <= POTS; i++) {
      potValue = readPot (i);
      printf ("  read pot %d\n", i);
      previousPotReadings [i] = potValue;
   }
}
