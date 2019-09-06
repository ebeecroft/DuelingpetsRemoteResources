#include <math.h>
double taxCalculation(int pointsDonated, double taxbase, double taxincrement);

double getTax(int& pointsDonated, double taxbase, double taxincrement)
{
   double tax = 0.0;
   tax = taxCalculation(pointsDonated, taxbase, taxincrement);
   pointsDonated = round(pointsDonated * tax);
   return tax;
}

double taxCalculation(int pointsDonated, double taxbase, double taxincrement)
{
   //Sets up the variable data
   int pointsbase = 10000;
   double tax = 0.0;
   bool rateFound = false;

   //Performs the calculations
   for(int i = 0; i < 100; i++)
   {
      //Identifies the tax bracket the user is in
      int taxbracket = (pointsbase + (pointsbase * i));
      if(pointsDonated < taxbracket)
      {
         //Sets the tax rate for the user 
         tax = taxbase + (taxincrement * i);
         rateFound = true;
         break;
      }
   }

   //Sets the tax rate to the highest setting
   if(!rateFound)
   {
      tax = taxbase * 100;
   }
   return tax;
}
