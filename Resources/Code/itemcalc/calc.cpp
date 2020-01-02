#include <stdlib.h>
#include <iostream>
void createitem(int petStats[], int& cost);
int main(int argc, char* argv[])
{
   if(argc == 18)
   {
      //Item creation code here
      int cost = 0;
      int count = 1;
      int limit = 17;
      int itemStats[limit];

      //Initializes the item's base stats
      for(int index = 0; index < limit; index++)
      {
         itemStats[index] = atoi(argv[count]);
         count++;
      }
      createitem(itemStats, cost);
      std::cout << cost;
   }
}