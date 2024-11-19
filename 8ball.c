#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *determineAnswer(int);
int calculateRandom();

char *positiveResponses[10] = {
	"It is certain",	 "It is decidedly so", "Without a doubt",
	"Yes definitely",	 "You may rely on it", "As I see it, yes",
	"Most likely",		 "Outlook good",	   "Yes",
	"Signs point to yes"};

char *ambiguousResponses[5] = {"Reply hazy, try again", "Ask again later",
							   "Better not tell you now", "Cannot predict now",
							   "Concentrate and ask again"};

char *negativeResponses[5] = {"Don't count on it", "My reply is no",
							  "My sources say no", "Outlook not so good",
							  "Very doubtful"};

int main(void) {
	srand(time(0)); // Generates a random seed

	int tryAgain = 1;

	puts("You pick up the magic 8-ball, eager to learn those secrets about "
		 "life that are only answered with a boolean expression.");

	while (tryAgain == 1) {

		puts("You look at the magic 8-ball and ask it a yes/no question: ");
		printf("You ask the 8-ball: ");

		char question[500];
		fgets(question, sizeof(question), stdin);

		int randomNumber = calculateRandom();
		char *answer = determineAnswer(randomNumber);

		puts("You shake the 8-ball. You see the murky water sloshing inside it "
			 "through its round window.");
		puts("Then, a brief moment of stillness is interrupted by the 8-ball's "
			 "answer, floating through the water.");
		puts("The 8-ball proclaims its answer:");
		printf("%s\n", answer);

		printf("Would you like to ask the 8-ball another question? (1 = Y/2 = "
			   "N): ");
		scanf("%d", &tryAgain);
	}
}

int calculateRandom() {
	int lowerBound = 1;
	int upperBound = 20;

	return rand() % (upperBound - lowerBound + 1) +
		   lowerBound; // Returns a number between 1 and 20, inclusive.
}

char *determineAnswer(int randomNumber) {

	if (randomNumber > 15) { // Negative responses
		return negativeResponses[20 - randomNumber];

	} else if (randomNumber > 10) { // Ambiguous responses
		return ambiguousResponses[15 - randomNumber];

	} else { // Positive responses
		return positiveResponses[10 - randomNumber];
	}
}
