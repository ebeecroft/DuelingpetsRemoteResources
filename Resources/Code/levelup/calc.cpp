#include <stdlib.h>
#include <iostream>
void levelup(int levelStats[], int& expGained, int& levelsGained, int& boostTokens);

int main(int argc, char* argv[])
{
   if(argc == 4)
   {
      //Retrieves the pets level, and experience
      int limit = 3, count = 1;
      int levelStats[limit];
      int expGained = 0, levelsGained = 0, boostTokens = 0;
      for(int index = 0; index < limit; index++)
      {
         levelStats[index] = atoi(argv[count]);
         count++;
      }

      //Returns the level results back to the website
      levelup(levelStats, expGained, levelsGained, boostTokens);
      std::cout << expGained << "," << levelsGained << "," << boostTokens;
   }
}
