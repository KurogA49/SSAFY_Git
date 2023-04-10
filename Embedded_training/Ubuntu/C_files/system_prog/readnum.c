#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int t = 1;
	int fd = open("./num.txt", O_RDONLY, 0);
	char buf[100] = {0};
	read(fd, buf, 100 - 1);
	t += atoi(buf);

	printf("%d\n", t);

	close(fd);

	return 0;
}
