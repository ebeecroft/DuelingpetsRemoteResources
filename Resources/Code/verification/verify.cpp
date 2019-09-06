#include <stdlib.h>
#include <iostream>
#include <string>
std::string botCheck(std::string color);
int main(int argc, char* argv[])
{
   if(argc == 2)
   {
      //Setup the bot verifictaion variables
      int count = 1;
      int limit = 1;
      std::string validUser = "Invalid";
      std::string color;

      //Initializes the color variable
      for(int index = 0; index < limit; index++)
      {
         color = (argv[count]);
         count++;
      }

      //Retrieves the result and passes back to ruby
      validUser = botCheck(color);
      std::cout << validUser;
   }
}
