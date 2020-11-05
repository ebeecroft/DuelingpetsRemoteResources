#include <stdlib.h>
#include <iostream>
void createmonster(int monsterStats[], int& level, int& cost, int& loot);
int main(int argc, char* argv[])
{
   if(argc == 12)
   {
      //Monster creation code here
      int level = 0, cost = 0, loot = 0;
      int count = 1;
      int limit = 11;
      int monsterStats[limit];

      //Initializes the monster's base stats
      for(int index = 0; index < limit; index++)
      {
         monsterStats[index] = atoi(argv[count]);
         count++;
      }
      createmonster(monsterStats, level, cost, loot);
      std::cout << cost << "," << level << "," << loot;
   }
}
