/*
* This program mimics the game of "Craps"
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
   printf("This program mimics the game of Craps\n");
   printf("Craps is a dice game in which players bet on\n");
   printf("the outcomes of the roll of a pair of dice\n");
   printf("Press Y or y to begin: \n");
   scanf("%c", &ans);
   
   if (ans == 'Y' | ans == 'y')
   {
      r1 = RollDice();
      r2 = RollDice();
      printf("Roll#1\n");
      printf("First Die: %d\n", r1);
      printf("Second Die: %d\n", r2);
      printf("Sum: %d\n",r1+r2);
      UserStatus(r1+r2);
   }
   else
      return (0);

}

int RollDice()
{
   int r = rand() % 6 + 1;
   return r;
}

void UserStatus(int sum)
{
   srand(time(NULL));
   int firstPt = sum;
   int r1, r2, secondPt;
   int counter = 2;
   enum status{WIN, LOSE, CONTINUE};
   enum status outcome;
   
   if ( sum==7 || sum==11 )
      outcome = WIN;
   else if ( sum==2 || sum==3 || sum==12 )
      outcome = LOSE;
   else
      outcome = CONTINUE;	
      
   switch(outcome)
   {
      case WIN: 
         printf("Congratulations! You won!\n");
         break;
         
      case LOSE:
         printf("Sorry, you lost!\n");
         break;
         
      case CONTINUE:
         do {
            printf("-----------------\n");
            printf("Roll number: %d\n", counter++);
            r1 = RollDice();
            r2 = RollDice();
            printf("Roll#%d\n", counter++);
            printf("First Die: %d\n", r1);
            printf("Second Die: %d\n", r2);
            printf("Sum: %d\n",r1+r2);
            secondPt = r1+r2;
         }while( !(secondPt==7) || !(secondPt==firstPt) );
         
         if (secondPt == 7)
            printf("Sorry, you lost!\n");
         else 
            printf("Congratulations! You won!\n");
         break;
      
   }

}
