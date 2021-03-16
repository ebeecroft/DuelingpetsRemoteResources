#include <math.h>

int getLevel(int petStats[]);
int getCost(int petStats[], int level, int baseCost);

void createpet(int petStats[], int& level, int& cost)
{
   if(petStats[14] > 0)
   {
      level = getLevel(petStats);

      //Short hand if statement for determining if there is an error
      if(level > 0) cost = getCost(petStats, level, petStats[15]);
      else cost = -1;
   }
   else
   {
      //Throws error if pet rarity is invalid
      level = -5;
      cost = -2;
   }
}

int getLevel(int petStats[])
{
   //Physical abilities
   int health = petStats[0];
   int attack = petStats[1];
   int defense = petStats[2];
   int agility = petStats[3];
   int strength = petStats[4];

   //Magic abilities
   int mp = petStats[5]; //can be 0, but has a min of 4
   int matk = petStats[6]; //Makes no sense if mp 0
   int mdef = petStats[7]; //Makes no sense if mp 0
   int magi = petStats[8]; //Makes no sense if mp 0
   int mstr = petStats[9]; //Makes no sense if mp 0

   //Stamina
   int hunger = petStats[10];
   int thirst = petStats[11];
   int fun = petStats[12];
   int lives = petStats[13];

   //14 points of stats are free to be assigned per level
   int level = 0;

   //Checks to see if the value is below the minimum
   if(mp == 0 && ((matk > 0 || mdef > 0) || (magi > 0 || mstr > 0)))
      level = -1;
   else if(mp >= 4 && ((matk < 1 || mdef < 1) || (magi < 1 || mstr < 1)))
      level = -2;
   else if(mp > 0 && mp < 4)
      level = -3;
   else
   {
      //Stores the value of the pets attributes
      int physical = health + attack + defense + agility + strength;
      int magical = mp + matk + mdef + magi + mstr;
      int stamina = hunger + thirst + fun + lives;

      //Determines the level of the pet
      int starterValue = 14;
      int additionalLevel = (physical + magical + stamina - starterValue);
      if((additionalLevel < 0) || (additionalLevel % 14 != 0)) level = -4;
      else level = 2 + (additionalLevel / 14);
   }
   return level;
}

int getCost(int petStats[], int level, int baseCost)
{
   //Physical cost(84 - 224 points)
   double healthValue = (petStats[0] * 16);
   double attackValue = (petStats[1] * 6);
   double defenseValue = (petStats[2] * 6);
   double agilityValue = (petStats[3] * 6);
   double strengthValue = (petStats[4] * 16);

   //Magical cost(168 - 392 points)
   double mpValue = (petStats[5] * 28);
   double matkValue = (petStats[6] * 12);
   double mdefValue = (petStats[7] * 12);
   double magiValue = (petStats[8] * 12);
   double mstrValue = (petStats[9] * 28);

   //Stamina cost(700 - 2800 points)
   double hungerValue = (petStats[10] * 50);
   double thirstValue = (petStats[11] * 50);
   double funValue = (petStats[12] * 50);
   double livesValue = (petStats[13] * 200);

   //User values(40 points)
   double rarityValue = (petStats[14] * 20); //Can't be zero
   double levelCost = 10 * level; //Can't be lower then 2

   //Stores the value of the various pet costs
   double physicalCost = healthValue + attackValue + defenseValue + agilityValue + strengthValue;
   double magicalCost = mpValue + matkValue + mdefValue + magiValue + mstrValue;
   double staminaCost = hungerValue + thirstValue + funValue + livesValue;

   //Calculates the cost of the current pet
   int cost = baseCost + round((levelCost + physicalCost + magicalCost + staminaCost + rarityValue));
   return cost;
}
