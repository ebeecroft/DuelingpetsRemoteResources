#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
double getAccuracy()
{
   double accuracy = (rand());
   return (accuracy / RAND_MAX);
}

void monsterbattle(int petStats[], int monsterStats[], int& petDamage, int& monsterDamage, int& petHPLeft, int& monsterHPLeft)
{
   //Initializes pet and monster variables
   srand(time(NULL));
   double combinedAgility = petStats[5] + monsterStats[5];
   double petAccuracy = (double) ((petStats[5] / combinedAgility));
   double monsterAccuracy = (double) ((monsterStats[5] / combinedAgility));
   double accuracyLevel1 = getAccuracy();
   double multiplier = 1.0;

   //Determines the amount of damage a pet does
   if(accuracyLevel1 <= petAccuracy)
   {
      //Normal Damage or Critical Hit
      int diceRoll = ((rand() % 80) + 1);
      if(diceRoll <= 4) multiplier = 1.25;
      else multiplier = 0.75;
   }
   else
   {
      //Determines if the pet misses or does 1/4 damage
      int diceRoll = ((rand() % 20) + 1);
      if(diceRoll <= 3) multiplier = 0;
      else multiplier = 0.125;
   }

   //Evaluates the result of the pet's attack
   if(multiplier != 0)
   {
      int attack = round((petStats[0] * petStats[3]) * multiplier);
      int defense = monsterStats[0] + monsterStats[4];
      if(attack > 1) petDamage = attack - (rand() % defense);
      else petDamage = 1;
      if(petDamage > 0) monsterHPLeft = monsterStats[1] - petDamage;
      else monsterHPLeft = monsterStats[1];
   }
   else
   {
      petDamage = 0;
      monsterHPLeft = monsterStats[1];
   }

   //Determines the amount of damage a monster does
   double accuracyLevel2 = getAccuracy();
   if(accuracyLevel2 <= monsterAccuracy)
   {
      //Normal Damage or Critical Hit
      int diceRoll = ((rand() % 80) + 1);
      if(diceRoll <= 4) multiplier = 1.25;
      else multiplier = 0.75;
   }
   else
   {
      //Determines if the mon misses or does 1/4 damage
      int diceRoll = ((rand() % 20) + 1);
      if(diceRoll <= 3) multiplier = 0;
      else multiplier = 0.125;
   }

   //Evaluates the result of the monster's attack
   if(multiplier != 0)
   {
      int attack = round((monsterStats[0] * monsterStats[3]) * multiplier);
      int defense = petStats[4] + petStats[6];
      if(attack > 1) monsterDamage = attack - (rand() % defense);
      else monsterDamage = 1;
      if(monsterDamage > 0) petHPLeft = petStats[1] - monsterDamage;
      else petHPLeft = petStats[1];
   }
   else
   {
      monsterDamage = 0;
      petHPLeft = petStats[1];
   }
}
