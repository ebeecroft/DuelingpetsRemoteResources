#include <stdlib.h>
#include <iostream>
void createitem(int petStats[], int& cost);
int main(int argc, char* argv[])
{
   if(argc == 25) //5
   {
      //Pet creation code here
      int cost = 0;
      int count = 1;
      int limit = 24;
      //22 Elements 0 - 21
      int itemStats[limit];
      //Initializes the pet's base stats
      for(int index = 0; index < limit; index++)
      {
         itemStats[index] = atoi(argv[count]);
         count++;
      }
      createitem(itemStats, cost); //Doesn't need level
      //Remember to return negatives for cost or level to indicate errors.
      std::cout << cost;
   }
}
