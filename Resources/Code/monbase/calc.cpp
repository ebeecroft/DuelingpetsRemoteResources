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
   //Base Stats 8 hp, 8 atk, 12 agi, 3 def, 10 exp,
   //5 nightmare, 30 shinycraze, 400 party
   double hp = (baseStats[0] * 0.5);
   double atk = (baseStats[1] * 4);
   double def = (baseStats[2] * 4);
   double agi = (baseStats[3] * 4);
   double exp = (baseStats[4] * 8);
   double nightmare = (baseStats[5] * 20);
   double shinycraze = (baseStats[6] * 8);
   double party = (baseStats[7] * 0.5);
   cost = round(hp + atk + def + agi + exp + nightmare + shinycraze + party);
}
