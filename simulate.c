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

void setControlPins (int pinValues[]) {
   // do something
}

int readPot (int potNo) {
   int muxPin = getMuxPinForPot (potNo);
   int ctrlPinValues[3];
   getControlPins (muxPin, ctrlPinValues);
   setControlPins (ctrlPinValues);
   int analogPin = getArduinoPinForPot (potNo);
   analogRead(analogPin);
   return -1;
}

void readPots () {
   printf ("readPots()\n");
   int i;
   for (i = 0; i < POTS; i++) {
      printf ("  read pot %d\n", i);
   }
}
