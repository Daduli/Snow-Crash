#include <fcntl.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int i = -1, fd = open(av[1], O_RDONLY);
	char buffer[25];

	read(fd, buffer, 25);
	buffer[25] = 0;
	while (buffer[++i])
		buffer[i] = buffer[i] - i;
	printf("%s\n", buffer);
}