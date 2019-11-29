#include <math.h>

int getLevel(int petStats[]);
int getCost(int petStats[], int level, int baseCost);

void createpet(int petStats[], int& level, int& cost)
{
   if(petStats[20] > 0)
   {
      level = getLevel(petStats);

      //Short hand if statement for determining if there is an error
      if(level > 0) cost = getCost(petStats, level, petStats[22]);
      else cost = -1;
   }
   else
   {
      level = -17;
      cost = -2;
   }
}

int getLevel(int petStats[])
{
   //20 points of stats are free to be assigned per level
   //Physical abilities(Should be allowed to be changed)
   int health = petStats[0]; //Health can't be 0 Min health: 16
   int attack = petStats[1]; //Can't be 0 Min attack: 3
   int defense = petStats[2]; //Can't be 0 Min defense: 3
   int speed = petStats[3]; //Can't be 0 Min speed: 3
   int luck = petStats[4]; //Can't be 0 Min luck: 3
   int strength = petStats[5]; //Strength can't be 0 Min strength: 4

   //Magic abilities(Should be allowed to be changed)
   int mp = petStats[6]; //can be 0, but has a min of 4
   int power = petStats[7]; //Makes no sense if mp 0
   int charms = petStats[8]; //Makes no sense if mp 0
   int force = petStats[9]; //Makes no sense if mp 0
   int concealment = petStats[10]; //Makes no sense if mp 0
   int flow = petStats[11]; //Makes no sense if mp 0

   //Pets needs(Should be allowed to be changed)
   int happyness = petStats[12]; //Happyness can't be 0 Min happyness: 16
   int will = petStats[13]; //Will can't be 0, used to see if you can still fight! Min will: 16
   int chubbyness = petStats[14]; //Chubbyness can't be 0 Min chubbyness: 8
   int hunger = petStats[15]; //Hunger can't be 0 Min hunger: 20
   int thirst = petStats[16]; //Thirst can't be 0 Min thirst: 20
   int fun = petStats[17]; //Fun can't be 0 Min fun: 8
   int rebirth = petStats[18]; // can be 0
   int lives = petStats[19]; //Lives can't be 0 Min lives: 2

   int level = 0;

   //Checks to see if the value is below the minimum
   if(health < 16)
      level = -1;
   else if(attack < 3)
      level = -2;
   else if(defense < 3)
      level = -3;
   else if(speed < 3)
      level = -4;
   else if(luck < 3)
      level = -5;
   else if(strength < 4)
      level = -6;
   else if(mp == 0 && ((((power > 0) || (charms > 0)) || ((force > 0) || (concealment > 0))) || (flow > 0)))
      level = -7;
   else if(happyness < 16)
      level = -8;
   else if(will < 16)
      level = -9;
   else if(chubbyness < 8)
      level = -10;
   else if(hunger < 20)
      level = -11;
   else if(thirst < 20)
      level = -12;
   else if(fun < 8)
      level = -13;
   else if(lives < 2)
      level = -14;
   else if(mp >= 4 && ((((power < 1) || (charms < 1)) || ((force < 1) || (concealment < 1))) || (flow < 1)))
      level = -15;
   else
   {
      //Stores the value of the pets attributes
      int physical = health + attack + defense + speed + luck + strength;
      int magical = mp + power + charms + force + concealment + flow;
      int stamina = happyness + will + chubbyness + hunger + thirst + fun;
      int commonality = rebirth + lives;

      //Determines the level of the pet
      int starterValue = 142;
      int additionalLevel = (physical + magical + stamina + commonality - starterValue);
      if(additionalLevel % 20 != 0) level = -16;
      else level = 2 + (additionalLevel / 20);
   }
   return level;
}

int getCost(int petStats[], int level, int baseCost)
{
   //Calculates the pet's value
   double levelCost = 6 * level;

   //Physical cost
   double healthValue = (petStats[0] * 0.25);
   double attackValue = (petStats[1] * 1);
   double defenseValue = (petStats[2] * 1);
   double speedValue = (petStats[3] * 1);
   double luckValue = (petStats[4] * 1);
   double strengthValue = (petStats[5] * 0.25);

   //Magical cost
   double mpValue = (petStats[6] * 0.25);
   double powerValue = (petStats[7] * 1);
   double charmsValue = (petStats[8] * 1);
   double forceValue = (petStats[9] * 1);
   double concealmentValue = (petStats[10] * 1);
   double flowValue = (petStats[11] * 1);

   //Pet value
   double happynessValue = (petStats[12] * 0.25);
   double willValue = (petStats[13] * 0.25);
   double chubbynessValue = (petStats[14] * 0.25);
   double hungerValue = (petStats[15] * 0.4);
   double thirstValue = (petStats[16] * 0.4);
   double funValue = (petStats[17] * 0.25);
   double rebirthValue = (petStats[18] * 0.2);
   double livesValue = (petStats[19] * 0.2);

   //User values
   double rarityValue = (petStats[20] * 6);
   double petValue = (petStats[21] * 0.4);

   //Stores the value of the various pet costs
   double physicalCost = healthValue + attackValue + defenseValue + speedValue + luckValue + strengthValue;
   double magicalCost = mpValue + powerValue + charmsValue + forceValue + concealmentValue + flowValue;
   double staminaCost =  happynessValue + willValue + chubbynessValue + hungerValue + thirstValue + funValue;
   double commonalityCost  = rebirthValue + livesValue + rarityValue + petValue;

   //Calculates the cost of the current pet
   int cost = baseCost + round((levelCost + physicalCost + magicalCost + staminaCost + commonalityCost));
   return cost;
}
