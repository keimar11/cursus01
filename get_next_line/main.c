#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"
#define LOG_FILE_PATH "test/test_empty.log"

int	main (void)
{
	int		fd;
	char	*buf;

	fd = open (LOG_FILE_PATH, O_RDONLY);
	fd = -1;
	buf = "\n";
	while(ft_strchr(buf, '\n') && buf != NULL)
	{
		buf = get_next_line(fd);
		printf("main: %s", buf);
		system("leaks a.out");
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
