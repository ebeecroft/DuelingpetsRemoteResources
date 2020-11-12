#include <stdlib.h>
#include <math.h>
#include <time.h>

void getloot(int& dreyoreGained)
{
   //Retrieves the dreyore earned from the battle
   srand(time(NULL));
   int dreyore = (rand() % 10) - 2;
   if(dreyore < 0){dreyore = 0;}
   dreyoreGained = dreyore;

   //Potential items here maybe
}
