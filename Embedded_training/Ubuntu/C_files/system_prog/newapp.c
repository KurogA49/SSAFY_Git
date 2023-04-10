#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main()
{
  int fd = open("test.txt", O_WRONLY, 0666);

	char buf[10] = "ABCDEFGH";
	write(fd, buf, strlen(buf));

	lseek(fd, 3, SEEK_SET);
	write(fd, "[NEW]\n", 7);	

  close(fd);
  return 0;
}
