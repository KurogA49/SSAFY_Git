#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int x = 0;
	char t = 'A';

	void *p1 = &x;
	void *p2 = &t;

	printf("%d\n", *(int *)p1);

	return 0;
}
