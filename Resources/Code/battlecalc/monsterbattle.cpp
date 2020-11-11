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
   double accuracy1 = getAccuracy();

   //Determines the amount of damage a pet does
   if(petAccuracy >= accuracy1)
   {
      int attack = round((petStats[0] * petStats[3]) * 3.5);
      int defense = round((monsterStats[0] * monsterStats[4]) * 1.5);
      int attackvalue = ((rand() % attack) + 1);
      int defensevalue = (rand() % defense);
      petDamage = attackvalue - defensevalue;
      if(petDamage > 0)
         monsterHPLeft = monsterStats[1] - petDamage;
      else
         monsterHPLeft = monsterStats[1];
   }
   else
   {
      petDamage = 0;
      monsterHPLeft = monsterStats[1];
   }
   
   //Determines the amount of damage a monster does
   double accuracy2 = getAccuracy();
   if(monsterAccuracy >= accuracy2)
   {
      int attack = round((monsterStats[0] * monsterStats[3]) * 2.75);
      int defense = round((petStats[4] * petStats[6]) * 1.5);
      int attackvalue = ((rand() % attack) + 1);
      int defensevalue = (rand() % defense);
      monsterDamage = attackvalue - defensevalue;
      if(monsterDamage > 0)
         petHPLeft = petStats[1] - monsterDamage;
      else
         petHPLeft = petStats[1];
   }
   else
   {
      monsterDamage = 0;
      petHPLeft = petStats[1];
   }
}
