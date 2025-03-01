#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAPE_WIDTH 16
typedef int tape;

tape get_random();
tape calc_next(tape t);
void print_tape(tape t);

int main()
{
	tape t;
	srand(time(NULL));
	t = get_random();
	print_tape(t);
	return EXIT_SUCCESS;
}

tape get_random()
{
	tape t;
	t = rand() % (1 << TAPE_WIDTH);
	return t;
}

tape calc_next(tape t)
{
	return t;
}

void print_tape(tape t)
{
	int i;
	for (i = (TAPE_WIDTH - 1); i >= 0; i--)
		printf("%i", (t >> i) & 1);
	putchar('\n');
}