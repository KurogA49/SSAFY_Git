#include <stdio.h>
#include <unistd.h>

int main()
{
	setbuf(stdout, NULL);
	while(1)
	{
		printf("t");
		usleep(300 * 1000);
	}
	printf("\n");
	return 0;
}
