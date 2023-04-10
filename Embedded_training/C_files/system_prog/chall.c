#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int fd = open("./cal.txt", O_RDONLY, 0);

	char buf[100] = {0};
	read(fd, buf, 100 - 1);
	close(fd);

	int n = atoi(buf);
	n *= 2;
	sprintf(buf, "%d", n);	
	printf("[======%d======]\n", n);

	fd = open("./cal.txt", O_WRONLY|O_TRUNC, 0);
	write(fd, buf, strlen(buf));
	close(fd);

	return 0;
}
