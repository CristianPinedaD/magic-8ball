all:
	gcc -Wall -Wextra -Wpedantic 8ball.c -o runGame

clean: 
	rm runGame