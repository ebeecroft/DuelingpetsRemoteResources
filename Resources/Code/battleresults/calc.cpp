#include <stdlib.h>
#include <iostream>
#include <string>
std::string battleresult(int health[]);

int main(int argc, char* argv[])
{
   if(argc == 3)
   {
      //Retrieves the pet and monster's health
      int limit = 2, count = 1;
      int health[limit];
      std::string result;
      for(int index = 0; index < limit; index++)
      {
         health[index] = atoi(argv[count]);
         count++;
      }
      
      //Returns the battle status back to the website
      result = battleresult(health);
      std::cout << result;
   }
}

std::string battleresult(int health[])
{
   //Determines who won the battle
   std::string result;
   if(health[0] > 0)
      result = "Win";
   else if(health[0] == 0 && health[1] == 0)
      result = "Draw";
   else
   {
      result = "Loss";
   }
   return result;
}
