#include <math.h>

int getLevel(int monsterStats[]);
int getCost(int monsterStats[], int level, int baseCost, int& loot);

void createmonster(int monsterStats[], int& level, int& cost, int& loot)
{
   if(monsterStats[12] > 0)
   {
      level = getLevel(monsterStats);

      //Short hand if statement for determining if there is an error
      if(level > 0) cost = getCost(monsterStats, level, monsterStats[13], loot);
      else cost = -1;
   }
   else
   {
      //Throws error if monster rarity is invalid
      level = -5;
      cost = -2;
      loot = -5;
   }
}

int getLevel(int monsterStats[])
{
   //Physical abilities
   int health = monsterStats[0];
   int attack = monsterStats[1];
   int defense = monsterStats[2];
   int agility = monsterStats[3];

   //Magic abilities
   int mp = monsterStats[4]; //can be 0, but has a min of 5
   int matk = monsterStats[5]; //Makes no sense if mp 0
   int mdef = monsterStats[6]; //Makes no sense if mp 0
   int magi = monsterStats[7]; //Makes no sense if mp 0

   //Monster stats
   int exp = monsterStats[8];
   int nightmare = monsterStats[9];
   int shinycraze = monsterStats[10];
   int party = monsterStats[11];

   //12 points of stats are free to be assigned per level
   int level = 0;

   //Checks to see if the value is below the minimum
   if(mp == 0 && ((matk > 0 || mdef > 0) || (magi > 0)))
      level = -1;
   else if(mp >= 5 && ((matk < 1 || mdef < 1) || (magi < 1)))
      level = -2;
   else if(mp > 0 && mp < 5)
      level = -3;
   else
   {
      //Stores the value of the monsters attributes
      int physical = health + attack + defense + agility;
      int magical = mp + matk + mdef + magi;
      int battle = exp + nightmare + shinycraze + party;

      //Determines the level of the monster
      int starterValue = 12;
      int additionalLevel = (physical + magical + battle - starterValue);
      if((additionalLevel < 0) || (additionalLevel % 12 != 0)) level = -4;
      else level = 2 + (additionalLevel / 12);
   }
   return level;
}

int getCost(int monsterStats[], int level, int baseCost, int& loot)
{
   //Physical cost(72 - 192 points)
   double healthValue = (monsterStats[0] * 16);
   double attackValue = (monsterStats[1] * 6);
   double defenseValue = (monsterStats[2] * 6);
   double agilityValue = (monsterStats[3] * 6);

   //Magical cost(144 - 336 points)
   double mpValue = (monsterStats[4] * 28);
   double matkValue = (monsterStats[5] * 12);
   double mdefValue = (monsterStats[6] * 12);
   double magiValue = (monsterStats[7] * 12);

   //Monster Trickery cost(480 points)
   double expValue = (monsterStats[8] * 40);
   double nightmareValue = (monsterStats[9] * 40);
   double shinycrazeValue = (monsterStats[10] * 40);
   double partyValue = (monsterStats[11] * 40);

   //User Values(50 points)
   loot = round(1 + ((level - 1) / 5));
   double lootValue = loot * 20; //loot min is 1
   double rarityValue = (monsterStats[12] * 20); //Can't be zero
   double levelCost = 10 * level; //Can't be lower than 2

   //Stores the value of the various monster costs
   double physicalCost = healthValue + attackValue + defenseValue + agilityValue;
   double magicalCost = mpValue + matkValue + mdefValue + magiValue;
   double userCost = lootValue + rarityValue + levelCost;
   double trickeryCost = expValue + nightmareValue + shinycrazeValue + partyValue;

   //Calculates the cost of the current monster
   int cost = baseCost + round((physicalCost + magicalCost + trickeryCost + userCost));
   return cost;
}
