#include <math.h>

int getCost(int petStats[], int baseCost);

void createitem(int petStats[], int& cost)
{
   if(petStats[20] > 0)
   {
      cost = getCost(petStats, petStats[22]);
   }
   else
   {
      cost = -2;
   }
}

int getCost(int petStats[], int baseCost)
{
   //Breads, Drinks and Potions cost
   double healthValue = (petStats[0] * 40);
   double chubbynessValue = (petStats[14] * 8);
   double hungerValue = (petStats[15] * 16);
   double thirstValue = (petStats[16] * 16);
   double willValue = (petStats[13] * 4);
   double funValue = (petStats[17] * 4);

   //Really expensive attributes
   double rebirthValue = (petStats[18] * 3000);
   double livesValue = (petStats[19] * 600);
   double rarityValue = (petStats[20] * 6); //26 for both fields
   double itemValue = (petStats[21] * 0.4);
   double durabilityValue = (petStats[23] * 10); //Sets the lowest value of an item

   //Battle cost
   double attackValue = (petStats[1] * 3);
   double defenseValue = (petStats[2] * 3);
   double speedValue = (petStats[3] * 3);
   double luckValue = (petStats[4] * 3);
   double strengthValue = (petStats[5] * 40);

   //Magical cost
   double mpValue = (petStats[6] * 80);
   double powerValue = (petStats[7] * 12);
   double charmsValue = (petStats[8] * 12);
   double forceValue = (petStats[9] * 80);
   double concealmentValue = (petStats[10] * 12);
   double flowValue = (petStats[11] * 12);

   //Pet value
   double happynessValue = (petStats[12] * 0.25);

   //Stores the value of the various pet costs
   double physicalCost = healthValue + attackValue + defenseValue + speedValue + luckValue + strengthValue;
   double magicalCost = mpValue + powerValue + charmsValue + forceValue + concealmentValue + flowValue;
   double staminaCost =  happynessValue + willValue + chubbynessValue + hungerValue + thirstValue + funValue;
   double commonalityCost  = rebirthValue + livesValue + rarityValue + itemValue;

   //Calculates the cost of the current pet
   int cost = baseCost + round((physicalCost + magicalCost + staminaCost + commonalityCost + durabilityValue));
   return cost;
}
