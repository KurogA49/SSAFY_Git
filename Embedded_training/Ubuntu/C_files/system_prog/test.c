#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int fd = open("./test.txt", O_WRONLY|O_TRUNC|O_CREAT, 0664);
	if(fd < 0)
	{
		printf("[%s :: %d] FILE	OPEN ERROR\n", __FILE__, __LINE__);
		exit(1);
	}

	char buf[1000] = "we can make it\n";
	int len = strlen(buf);
	write(fd, buf, len);

	close(fd);

	return 0;
}
