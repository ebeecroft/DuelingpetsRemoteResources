#include <stdlib.h>
#include <iostream>
void monsterbattle(int petStats[], int monsterStats[], int& petDamage, int& monsterDamage, int& petHPLeft, int& monsterHPLeft);
int main(int argc, char* argv[])
{
   if(argc == 27)
   {
      //Initializes the pet's base stats
      int count = 1;
      int petlimit = 14;
      int petStats[petlimit];
      int petDamage = 0, petHPLeft = 0;
      for(int index = 0; index < petlimit; index++)
      {
         petStats[index] = atoi(argv[count]);
         count++;
      }
      //std::cout << "I work fine here";
      //Initializes the monster's base stats
      int monlimit = 12;
      int monsterStats[monlimit];
      int monsterDamage = 0, monsterHPLeft = 0;
      for(int index = 0; index < monlimit; index++)
      {
         monsterStats[index] = atoi(argv[count]);
         count++;
      }
      
      //Returns the battle result back to the website
      monsterbattle(petStats, monsterStats, petDamage, monsterDamage, petHPLeft, monsterHPLeft);
      std::cout << petDamage << "," << monsterDamage << "," << petHPLeft << "," << monsterHPLeft;
   }
}
