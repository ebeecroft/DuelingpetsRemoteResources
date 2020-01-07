#include <math.h>

int getCost(int petStats[], int baseCost);

void createitem(int petStats[], int& cost)
{
   if((petStats[13] > 0 && petStats[14] > 0) && (petStats[4] >= 0 && petStats[9] >= 0))
   {
      cost = getCost(petStats, petStats[16]);
   }
   else
   {
      if(petStats[4] < 0)
         cost = -1;
      else if(petStats[9] < 0)
         cost = -2;
      else if(petStats[13] <= 0)
         cost = -3;
      else if(petStats[14] <= 0)
         cost = -4;
   }
}

int getCost(int petStats[], int baseCost)
{
   //Battle physical costs
   double attackValue = (petStats[1] * 10);
   double defenseValue = (petStats[2] * 10);
   double agilityValue = (petStats[3] * 10);
   double strengthValue = (petStats[4] * 30); //Strength can never be negative

   //Battle magical costs
   double matkValue = (petStats[6] * 30);
   double mdefValue = (petStats[7] * 30);
   double magiValue = (petStats[8] * 30);
   double mstrValue = (petStats[9] * 90); //Mstr can never be negative

   //Stamina costs
   double hpValue = (petStats[0] * 8);
   double mpValue = (petStats[5] * 8);
   double hungerValue = (petStats[10] * 30);
   double thirstValue = (petStats[11] * 30);
   double funValue = (petStats[12] * 160);

   //Item attributes
   double durabilityValue = (petStats[13] * 20); //Can never be zero
   double rarityValue = (petStats[14] * 20); //Can never be zero
   double itemValue = (petStats[15] * 0.4);

   //Stores the value of the various pet costs
   double physicalCost = attackValue + defenseValue + agilityValue + strengthValue;
   double magicalCost = matkValue + mdefValue + magiValue + mstrValue;
   double staminaCost =  hpValue + mpValue + hungerValue + thirstValue + funValue;
   double commonalityCost  = rarityValue + itemValue + durabilityValue;

   //Calculates the cost of the current pet
   int cost = baseCost + round((physicalCost + magicalCost + staminaCost + commonalityCost));
   return cost;
}
