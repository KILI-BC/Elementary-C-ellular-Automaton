#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*has to be at least 3 for the code to work*/
#define TAPE_WIDTH 30
#define WOLFRAM_CODE 30
#define EVALUATE_CODE(c) ((WOLFRAM_CODE >> ((c) & 7)) & 1)
typedef int tape;

tape get_random();
tape calc_next(tape t);
void print_tape(tape t);

int main()
{
	tape t = 0x34244103;
	srand(time(NULL));
	while (1)
	{
		print_tape(t);
		t = calc_next(t);
	}

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
	int i;
	tape ret = 0;

	/*handle leftmost bit*/
	ret |= (EVALUATE_CODE((t >> (TAPE_WIDTH - 2)) | (t << 2)) << (TAPE_WIDTH - 1));

	/*handle middle bits*/
	for (i = (TAPE_WIDTH - 2); i > 0; i--)
		ret |= (EVALUATE_CODE(t >> (i - 1)) << i);

	/*handle rightmost bit*/
	ret |= EVALUATE_CODE((t << 1) | (t >> (TAPE_WIDTH - 1)));
	return ret;
}

void print_tape(tape t)
{
	int i;
	for (i = (TAPE_WIDTH - 1); i >= 0; i--)
		printf("%i", (t >> i) & 1);
	putchar('\n');
}