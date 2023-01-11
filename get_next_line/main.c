#include <fcntl.h>
#include "get_next_line.h"

int	main (int argc, char **argv)
{
	int		fd;
	char	*buf;

	(void)argc;
	fd = open (argv[1], O_RDONLY);
	while(1)
	{
		buf = get_next_line(fd);
		printf("%s", buf);
		if (buf == NULL)
			break;
	}
	close (fd);
	return (0);
}

// int main(void)
// {
// 	char str[100];
// 	int fd;

// 	fd = 0;
// 	read(fd, str,10);
// 	printf("%s", str);
// }
