

/*
*NumberGuessingGame
*This program creates a random number between 1 and 100
*It lets you guess which number has been created
*Returns the number of needed guesses
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int num;
	int cNum;
	int high = 100;
	int low = 1;
	int count = 0;
	time_t t;
	
	/*Initialize random number generator*/
	srand((unsigned int)t);

	printf("Choosing random number...\n");
	
	/*Choose random number to be guessed*/
	cNum = (rand()%(high-low+1))+low; 
	
	printf("Random number chosen.\n");
	printf("Please insert your guess: \n");
	
	while (cNum){
	scanf("%i", &num);
	count += 1;
		if (cNum > num) {
			printf("You guessed too low. Try again.");
		} else if (cNum < num) {
			printf("You guessed too high. Try again.");
		} else {
			printf("Correct the chosen random number was ");
			printf("%i", cNum);
			printf(". You needed to guess ");
			printf("%i", count);
			printf(" times to get there.\n\n\n\n\n\n\n");
			break;
		}
	}
	return(0);
}
