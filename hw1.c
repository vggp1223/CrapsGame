/*
* This program mimics the game of "Craps".
* Craps is a dice game in which players bet on
* the outcomes of the roll of a pair of dice. 
*
* Created by Virginia Gonzalez
* September 27, 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int RollDice();
void UserStatus(int sum);

int main(void)
{
   // User input variables
   srand(time(NULL));
   char ans;
   int r1, r2;
   
   // Display program concept
   printf("\nThis program mimics the game of Craps\n");
   printf("Craps is a dice game in which players bet on\n");
   printf("the outcomes of the roll of a pair of dice\n");
   printf("Press Y or y to play: ");
   scanf("%c", &ans); // Save input from the user
   
   // If user wants to play, then proceed
   if (ans == 'Y' || ans == 'y')
   {
      // Obtain two random integer variables
      r1 = RollDice();
      r2 = RollDice();
      
      // Print the output of the random variables and its sum
      printf("\nRoll#1\n");
      printf("First Die: %d\n", r1);
      printf("Second Die: %d\n", r2);
      printf("Sum: %d\n",r1+r2);
      
      // Call the function to check if the user won or lost
      UserStatus(r1+r2);
   }
   // If the user doesn't want to play, then exit the program
    else
       return (0);
  
}

//  Function to return a random integer
int RollDice()
{
   int r = rand() % 6 + 1;
   return r;
}

// Function to display if the user won or lost
void UserStatus(int sum)
{
   // Seed the random number generator
   srand(time(NULL));
   
   // Variables 
   int firstPt = sum;
   int r1, r2, secondPt;
   int counter = 2;
   
   // enum data type called status where
   // WIN=1, LOSE=2, and CONTINUE=3
   enum status{WIN, LOSE, CONTINUE};
   enum status outcome;
   
   // If the sum of first roll is either 7 or 11
   if ( sum==7 || sum==11 )
      outcome = WIN;
   // If the sum of the first roll is either 2,3, or 12
   else if ( sum==2 || sum==3 || sum==12 )
      outcome = LOSE;
   // All other possibilities
   else
      outcome = CONTINUE;	
      
   // Display the corresponding status of outcome
   switch(outcome)
   {
      case WIN: 
         printf("Congratulations! You won!\n");
         break;
         
      case LOSE:
         printf("Sorry, you lost!\n");
         break;
         
      case CONTINUE:
         // Continuous loop until the sum of the first roll or 7 is reached
         do {
            printf("\n-----------------\n");
            r1 = RollDice();
            r2 = RollDice();
            printf("Roll#%d\n", counter++);
            printf("First Die: %d\n", r1);
            printf("Second Die: %d\n", r2);
            printf("Sum: %d\n",r1+r2);
            secondPt = r1+r2;
         }while( !(secondPt==7) && !(secondPt==firstPt) );
         
         // Display the outcome of the last roll
         if (secondPt == 7)
            printf("Sorry, you lost!\n");
         else 
            printf("Congratulations! You won!\n");
         break;
      
   }

}
