#include <stdlib.h>
#include <iostream>
double getTax(int& pointsDonated, double taxincrement);
int main(int argc, char* argv[])
{
   if(argc == 3)
   {
      //Setup up of donation variables
      int count = 1, limit = 1;
      int pointsTaxed = 0;
      double tax = 0.0, taxincrement = 0.0;

      //Initializes the points variable
      for(int index = 0; index < limit; index++)
      {
         pointsTaxed = atoi(argv[count]);
         taxincrement = atof(argv[2]);
         count++;
      }

      //Retrieves donation points and returns them to ruby
      tax = getTax(pointsTaxed, taxincrement);
      std::cout << pointsTaxed << "," << tax << std::endl;
   }
}
