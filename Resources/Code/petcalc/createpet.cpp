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
      level = -13;
      cost = -2;
   }
}

int getLevel(int petStats[])
{
   //Physical abilities(26 points)
   int health = petStats[0]; //Health can't be 0 Min health: 16
   int attack = petStats[1]; //Can't be 0 Min attack: 2
   int defense = petStats[2]; //Can't be 0 Min defense: 2
   int agility = petStats[3]; //Can't be 0 Min speed: 2
   int strength = petStats[4]; //Strength can't be 0 Min strength: 4

   //Magic abilities(Should be allowed to be changed)
   int mp = petStats[5]; //can be 0, but has a min of 4
   int matk = petStats[6]; //Makes no sense if mp 0
   int mdef = petStats[7]; //Makes no sense if mp 0
   int magi = petStats[8]; //Makes no sense if mp 0
   int mstr = petStats[9]; //Makes no sense if mp 0

   //Stamina(28 points)
   int hunger = petStats[10]; //Hunger can't be 0 Min hunger: 10
   int thirst = petStats[11]; //Thirst can't be 0 Min thirst: 10
   int fun = petStats[12]; //Fun can't be 0 Min fun: 8
   int lives = petStats[13]; // can be 0

   //14 points of stats are free to be assigned per level
   int level = 0;

   //Checks to see if the value is below the minimum
   if(health < 16)
      level = -1;
   else if(attack < 2)
      level = -2;
   else if(defense < 2)
      level = -3;
   else if(agility < 2)
      level = -4;
   else if(strength < 4)
      level = -5;
   else if(mp == 0 && ((matk > 0 || mdef > 0) || (magi > 0 || mstr > 0)))
      level = -6;
   else if(mp >= 4 && ((matk < 1 || mdef < 1) || (magi < 1 || mstr < 1)))
      level = -7;
   else if(mp > 0 && mp < 4)
      level = -8;
   else if(hunger < 10)
      level = -9;
   else if(thirst < 10)
      level = -10;
   else if(fun < 8)
      level = -11;
   else
   {
      //Stores the value of the pets attributes
      int physical = health + attack + defense + agility + strength;
      int magical = mp + matk + mdef + magi + mstr;
      int stamina = hunger + thirst + fun + lives;

      //Determines the level of the pet
      int starterValue = 68;
      int additionalLevel = (physical + magical + stamina - starterValue);
      if((additionalLevel < 0) || (additionalLevel % 14 != 0)) level = -12;
      else level = 2 + (additionalLevel / 14);
   }
   return level;
}

int getCost(int petStats[], int level, int baseCost)
{
   //Physical cost(36 points)
   double healthValue = (petStats[0] * 0.5);
   double attackValue = (petStats[1] * 2);
   double defenseValue = (petStats[2] * 2);
   double agilityValue = (petStats[3] * 2);
   double strengthValue = (petStats[4] * 4);

   //Magical cost(64 points optional if free points used) //14 points available
   double mpValue = (petStats[5] * 2);
   double matkValue = (petStats[6] * 4);
   double mdefValue = (petStats[7] * 4);
   double magiValue = (petStats[8] * 4);
   double mstrValue = (petStats[9] * 8);

   //Stamina cost(280 points)Base like cost
   double hungerValue = (petStats[10] * 10);
   double thirstValue = (petStats[11] * 10);
   double funValue = (petStats[12] * 10);
   double livesValue = (petStats[13] * 30);

   //Prior to user value 380 points

   //User values(80 points)
   double rarityValue = (petStats[14] * 40); //Can't be zero
   double levelCost = 20 * level; //Can't be lower then 2

   //Stores the value of the various pet costs
   double physicalCost = healthValue + attackValue + defenseValue + agilityValue + strengthValue;
   double magicalCost = mpValue + matkValue + mdefValue + magiValue + mstrValue;
   double staminaCost = hungerValue + thirstValue + funValue + livesValue;

   //Calculates the cost of the current pet
   int cost = baseCost + round((levelCost + physicalCost + magicalCost + staminaCost + rarityValue));
   return cost;
}
