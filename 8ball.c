#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *determineAnswer(int);
int calculateRandom();
void pressAnyKeyToContinue();
void ending();

const char *positiveResponses[10] = {
	"It is certain",	 "It is decidedly so", "Without a doubt",
	"Yes definitely",	 "You may rely on it", "As I see it, yes",
	"Most likely",		 "Outlook good",	   "Yes",
	"Signs point to yes"};

const char *ambiguousResponses[5] = {"Reply hazy, try again", "Ask again later",
							   "Better not tell you now", "Cannot predict now",
							   "Concentrate and ask again"};

const char *negativeResponses[5] = {"Don't count on it", "My reply is no",
							  "My sources say no", "Outlook not so good",
							  "Very doubtful"};
const char *endings[10] = {
	"You check the ball one last time. It flashes a message: 'All done! "
	"Now go conquer the world... or at least fold your laundry. Small "
	"steps!'",

	"You give the ball a final shake, and the answer appears: 'By the "
	"way, everything I said was based on random chance. Good luck!'",

	"The ball's screen lights up with a final response: 'Great session! "
	"But let's be honest—would you have listened to my answers anyway?'",

	"You look at the ball, and it offers its last bit of wisdom: 'You're "
	"welcome! Don't spend all your time questioning the mysteries of the "
	"universe, okay?'",

	"You hold the ball up, expecting one last answer. Instead, it says: 'Are "
	"my answers truly meaningful, or are we all just floating in an endless "
	"sea of possibilities? Anyway, see ya!'",

	"As you check the ball one last time, a message scrolls across: "
	"'Congratulations! You've unlocked the Secret of the Universe! …Oh wait, "
	"no, it's just a coupon for a free coffee. Enjoy!'",

	"You glance at the ball for any final advice. It replies coolly, 'Glad I "
	"could provide guidance. Remember, I'm just a ball of random responses, so "
	"if things go south... not my fault!'",

	"With a last look, you notice the ball glowing with a message: 'Another "
	"job well done! And all without a single typo. Take note, humans!'",

	"You look at the ball for one more nugget of wisdom. It simply says, 'So, "
	"got any more burning questions? Oh wait… I'm done answering. Better luck "
	"next time!'",

	"You peer at the ball for its parting words, and it displays: 'You've "
	"asked, I've answered. Go forth boldly… and maybe don't rely on a magic "
	"ball next time!'"
};

int main(void) {
	srand(time(0)); // Generates a random seed

	int tryAgain = 1;

	puts("You pick up the magic 8-ball, eager to learn those secrets about "
		 "life that are only answered with a boolean expression.");

	pressAnyKeyToContinue();

	while (tryAgain == 1) {
	
	    srand(time(0)); 

		puts("You look at the magic 8-ball and ask it a yes/no question: ");

		printf("\nYou ask the 8-ball: ");

		char question[500];
		fgets(question, sizeof(question), stdin);

		int randomNumber = calculateRandom();
		char *answer = determineAnswer(randomNumber);

		puts("You shake the 8-ball. You see the murky water sloshing inside it "
			 "through its round window.");

		pressAnyKeyToContinue();

		puts("Then, a brief moment of stillness is interrupted by the 8-ball's "
			 "answer, floating through the water.");

		pressAnyKeyToContinue();

		puts("The 8-ball proclaims its answer:");
		printf("%s", answer);
		puts("");

		pressAnyKeyToContinue();

		printf("Would you like to ask the 8-ball another question? (1 = Y  2 = "
			   "N): ");
		scanf("%d", &tryAgain);

		system("clear");
	}

	ending(); 
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

void pressAnyKeyToContinue(){
	printf("\033[90mPress any key to continue...\033[0m");
	getchar();
}

void ending() {
	int lowerBound = 0;
	int upperBound = 9;

	int randomNum = rand() % (upperBound - lowerBound + 1) + lowerBound;

	printf("%s\n", endings[randomNum]);
}