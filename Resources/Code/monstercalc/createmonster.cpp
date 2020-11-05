#include <math.h>

int getLevel(int monsterStats[]);
int getCost(int monsterStats[], int level, int baseCost, int& loot);

void createmonster(int monsterStats[], int& level, int& cost, int& loot)
{
   if(monsterStats[9] > 0)
   {
      level = getLevel(monsterStats);

      //Short hand if statement for determining if there is an error
      if(level > 0) cost = getCost(monsterStats, level, monsterStats[10], loot);
      else cost = -1;
   }
   else
   {
      //Throws error if monster rarity is invalid
      level = -10;
      cost = -2;
      loot = -5;
   }
}

int getLevel(int monsterStats[])
{
   //Physical abilities(78 points)
   int health = monsterStats[0]; //Health can't be 0 Min health: 30(54 hp)
   int attack = monsterStats[1]; //Can't be 0 Min attack: 16(8 atk)
   int defense = monsterStats[2]; //Can't be 0 Min defense: 16(8 def)
   int agility = monsterStats[3]; //Can't be 0 Min speed: 16(8 spd)

   //Magic abilities(Should be allowed to be changed)
   int mp = monsterStats[4]; //can be 0, but has a min of 5
   int matk = monsterStats[5]; //Makes no sense if mp 0
   int mdef = monsterStats[6]; //Makes no sense if mp 0
   int magi = monsterStats[7]; //Makes no sense if mp 0

   //Monster stats(10 points)
   int exp = monsterStats[8]; //Minimum exp is 10

   //18 points of stats are free to be assigned per level (Might tripple)
   int level = 0;

   //Checks to see if the value is below the minimum
   if(health < 30)
      level = -1;
   else if(attack < 16)
      level = -2;
   else if(defense < 16)
      level = -3;
   else if(agility < 16)
      level = -4;
   else if(mp == 0 && ((matk > 0 || mdef > 0) || (magi > 0)))
      level = -5;
   else if(mp >= 5 && ((matk < 1 || mdef < 1) || (magi < 1)))
      level = -6;
   else if(mp > 0 && mp < 5)
      level = -7;
   else if(exp < 10)
      level = -8;
   else
   {
      //Stores the value of the monsters attributes
      int physical = health + attack + defense + agility;
      int magical = mp + matk + mdef + magi;

      //Determines the level of the monster
      int starterValue = 106;
      int additionalLevel = (physical + magical + exp - starterValue);
      if((additionalLevel < 0) || (additionalLevel % 18 != 0)) level = -9;
      else level = 2 + (additionalLevel / 18);
   }
   return level;
}

int getCost(int monsterStats[], int level, int baseCost, int& loot)
{
   //Physical cost(303 points)
   double healthValue = (monsterStats[0] * .5);
   double attackValue = (monsterStats[1] * 6);
   double defenseValue = (monsterStats[2] * 6);
   double agilityValue = (monsterStats[3] * 6);

   //Magical cost(360 points optional if free points used) //18 points available
   double mpValue = (monsterStats[4] * 12);
   double matkValue = (monsterStats[5] * 24);
   double mdefValue = (monsterStats[6] * 24);
   double magiValue = (monsterStats[7] * 24);
   
   //Monster values(640 points)
   double expValue = (monsterStats[8] * 40);
   loot = round(1 + ((level - 1) / 5));
   double lootValue = loot * 40; //loot min is 1
   double rarityValue = (monsterStats[9] * 120); //Can't be zero
   double levelCost = 40 * level; //Can't be lower than 2

   //Stores the value of the various monster costs
   double physicalCost = healthValue + attackValue + defenseValue + agilityValue;
   double magicalCost = mpValue + matkValue + mdefValue + magiValue;
   double monsterCost = expValue + lootValue + rarityValue + levelCost;

   //Calculates the cost of the current monster
   int cost = baseCost + round((physicalCost + magicalCost + monsterCost));
   return cost;
}
