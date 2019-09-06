#include <string>
std::string botCheck(std::string color)
{
   int limit = 12;
   std::string commonColors[limit] = {"red", "blue", "green", "cyan", "pink", "purple", "orange", "magenta", 
   "brown", "yellow", "white", "black"};
   std::string validUser = "Invalid";

   //Checks to see if we are looking at a valid color
   for(int i = 0; i < limit; i++)
   {
      //if(color.compare(commonColors[i]))
      if(color == commonColors[i])
      {
         validUser = "Valid";
         break;
      }
   }
   return validUser;
}
