#include <stdlib.h>
#include <iostream>
void createpet(int petStats[], int& level, int& cost);
int main(int argc, char* argv[])
{
   if(argc == 18)
   {
      //Pet creation code here
      int level = 0, cost = 0;
      int count = 1;
      int limit = 17;
      int petStats[limit];

      //Initializes the pet's base stats
      for(int index = 0; index < limit; index++)
      {
         petStats[index] = atoi(argv[count]);
         count++;
      }
      createpet(petStats, level, cost);
      std::cout << cost << "," << level;
   }
}
