#include <stdlib.h>
#include <math.h>
#include <time.h>

void levelup(int levelStats[], int& expGained, int& levelsGained, int& boostTokens)
{
   //Determines the amount of exp that the pet gets
   srand(time(NULL));
   int minexp = round(levelStats[2] - (levelStats[2] * 0.4));
   int maxexp = round(levelStats[2] + (levelStats[2] * 0.4));
   int exp = (minexp + (rand() % (maxexp - minexp + 1)));
   int petexp = (levelStats[1] + exp);
   bool levelEnd = false;
   expGained = exp;
   levelStats[1] = petexp;

   while(!levelEnd)
   {
      //Calculates the next level
      int nextLevel = round((800 * pow(levelStats[0] + 1, 3))/40);
      if(petexp >= nextLevel)
      {
         //Stores the levels gained and also the boost tokens
         int petLevel = levelStats[0] + 1;
         levelStats[0] = petLevel;
         levelsGained += 1;
         int tokens = 7;
         boostTokens += tokens;
      }
      else{levelEnd = true;}
   }
}
