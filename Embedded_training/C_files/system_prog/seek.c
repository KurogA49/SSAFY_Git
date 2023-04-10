#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int fd = open("./test.txt", O_RDONLY, 0);
	if(fd < 0)
	{
		printf("FILE OPEN ERROR\n");
		exit(1);
	}

	char buf[11] = {0};
	int n;

	n = lseek(fd, 0, SEEK_CUR);
	printf("%d\n", n);
	read(fd, buf, 10);
	printf("%s\n", buf);

	n = lseek(fd, 0, SEEK_CUR);
	printf("%d\n", n);

	memset(buf, 0, 10);
	read(fd, buf, 5);
	printf("%s\n", buf);
	n = lseek(fd, 0, SEEK_CUR);
	printf("%d\n", n);

	close(fd);
    return 0;
}
