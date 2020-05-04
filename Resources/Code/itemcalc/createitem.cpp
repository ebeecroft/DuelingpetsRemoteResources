#include <math.h>

int getCost(int itemStats[], int baseCost);

void createitem(int itemStats[], int& cost)
{
   if((itemStats[13] > 0 && itemStats[14] > 0) && (itemStats[4] >= 0 && itemStats[9] >= 0))
   {
      cost = getCost(itemStats, itemStats[15]);
   }
   else
   {
      if(itemStats[4] < 0)
         cost = -1;
      else if(itemStats[9] < 0)
         cost = -2;
      else if(itemStats[13] <= 0)
         cost = -3;
      else if(itemStats[14] <= 0)
         cost = -4;
   }
}

int getCost(int itemStats[], int baseCost)
{
   //Battle physical costs
   double attackValue = (itemStats[1] * 6); //8 atk = 1 str
   double defenseValue = (itemStats[2] * 6); //8 def = 1 str
   double agilityValue = (itemStats[3] * 6); //8 agi = 1 str
   double strengthValue = (itemStats[4] * 48); //Strength can never be negative

   //Battle magical costs
   double matkValue = (itemStats[6] * 24); //8 matk = 1 mstr
   double mdefValue = (itemStats[7] * 24); //8 mdef = 1 mstr
   double magiValue = (itemStats[8] * 24); //8 magi = 1 mstr
   double mstrValue = (itemStats[9] * 192); //Mstr can never be negative

   //Stamina costs
   double hpValue = (itemStats[0] * 80);
   double mpValue = (itemStats[5] * 80);
   double hungerValue = (itemStats[10] * 5); //16 hunger = 1 hp
   double thirstValue = (itemStats[11] * 5); //16 thirst = 1 hp
   double funValue = (itemStats[12] * 240); //Previous was 160

   //Item attributes
   double durabilityValue = (itemStats[13] * 20); //Can never be zero
   double rarityValue = (itemStats[14] * 20); //Can never be zero

   //Stores the value of the various pet costs
   double physicalCost = attackValue + defenseValue + agilityValue + strengthValue;
   double magicalCost = matkValue + mdefValue + magiValue + mstrValue;
   double staminaCost =  hpValue + mpValue + hungerValue + thirstValue + funValue;
   double commonalityCost  = rarityValue + durabilityValue;

   //Calculates the cost of the current pet
   int cost = baseCost + round((physicalCost + magicalCost + staminaCost + commonalityCost));
   return cost;
}
