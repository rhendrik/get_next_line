#include "get_next_line.h"
#include <fcntl.h>

int main(int ac, char **av)
{
	(void) ac;
	int fd;
	char *line;

	fd = open(av[1], O_RDONLY);
	while(get_next_line(fd, &line) != 0)
	{
		ft_putendl(line);
	}
	return (0);
}
