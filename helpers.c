#include <stdio.h>
#include "hello.h"

void getControlPins (int number, int pins[]) {

  int divByFour = 0;
  int modByFour	= 0;
  int divByTwo 	= 0;
  int modByTwo 	= 0;
  int divByOne  = 0;

  divByFour = number / 4;
  modByFour = number % 4;

  if (modByFour > 0) {
    divByTwo = modByFour / 2;
    modByTwo = modByFour % 2;
    if (modByTwo > 0)
      divByOne = modByTwo;
  }

  pins[2] = divByFour;
  pins[1] = divByTwo;
  pins[0] = divByOne;

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

void getControlPins2 (int number, int pins[]) {
   pins[0] = NUMBER_CTRL_PIN_MATRIX[number][0];
   pins[1] = NUMBER_CTRL_PIN_MATRIX[number][1];
   pins[2] = NUMBER_CTRL_PIN_MATRIX[number][2];
}
 
void test1(int number) {
  int res[3];
  getControlPins (number, res);
  printf ("number = %d\n", number);
  printf (" s0 = %d\n", res[0]);
  printf (" s1 = %d\n", res[1]);
  printf (" s2 = %d\n", res[2]);
}

void test2(int number) {
  int res[3];
  getControlPins2 (number, res);
  printf ("number = %d\n", number);
  printf (" s0 = %d\n", res[0]);
  printf (" s1 = %d\n", res[1]);
  printf (" s2 = %d\n", res[2]);
}

void getControlPinsTests () {
   int i;
   for (i = 0; i < 8; i++) {
      test1(i);
      test2(i);
   }
}
