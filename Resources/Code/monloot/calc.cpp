#include <stdlib.h>
#include <iostream>
void getloot(int& dreyoreGained);

int main(int argc, char* argv[])
{
   if(argc == 3)
   {
      //Retrieves the monster's level, and loot
      int limit = 2, count = 1;
      int loot[limit];
      int dreyoreGained = 0;
      for(int index = 0; index < limit; index++)
      {
         loot[index] = atoi(argv[count]);
         count++;
      }

      //Returns the loot results back to the website
      getloot(dreyoreGained);
      std::cout << dreyoreGained;
   }
}
