#include <stdlib.h>
#include <iostream>
#include <math.h>
void calccost(int baseStats[], int& cost);

int main(int argc, char* argv[])
{
   if(argc == 9)
   {
      //Pet creation code here
      int level = 0, cost = 0;
      int count = 1;
      int limit = 8;
      int baseStats[limit];

      //Initializes the pet's base stats
      for(int index = 0; index < limit; index++)
      {
         baseStats[index] = atoi(argv[count]);
         count++;
      }
      calccost(baseStats, cost);
      std::cout << cost;
   }
}

void calccost(int baseStats[], int& cost)
{
   //Base Stats 16 hp, 4 atk, 9 agi, 11 def, 3 str,
   //16 hunger, 16 thirst, 8 fun
   double hp = (baseStats[0] * 0.5);
   double atk = (baseStats[1] * 4);
   double def = (baseStats[2] * 4);
   double agi = (baseStats[3] * 4);
   double str = (baseStats[4] * 12);
   double hunger = (baseStats[5] * 2);
   double thirst = (baseStats[6] * 2);
   double fun = (baseStats[7] * 8);
   cost = round(hp + atk + def + agi + str + hunger + thirst + fun);
}
