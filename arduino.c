#include <stdio.h>
#include "helpers.h"
#include "simulate.h"

int main (void)
{
   setup();
   while (1) {
      loop();
   }
   return 0;
}
