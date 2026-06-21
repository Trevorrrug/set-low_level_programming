#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
0-positive_or_negative.c int n, last;

0-positive_or_negative.c srand(time(0));
0-positive_or_negative.c n = rand() - RAND_MAX / 2;

0-positive_or_negative.c last = n % 10;

0-positive_or_negative.c printf("Last digit of %d is %d ", n, last);

0-positive_or_negative.c if (last > 5)
0-positive_or_negative.c 0-positive_or_negative.c printf("and is greater than 5\n");
0-positive_or_negative.c else if (last == 0)
0-positive_or_negative.c 0-positive_or_negative.c printf("and is 0\n");
0-positive_or_negative.c else
0-positive_or_negative.c 0-positive_or_negative.c printf("and is less than 6 and not 0\n");

0-positive_or_negative.c return (0);
}
