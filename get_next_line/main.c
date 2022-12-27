#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"
#define LOG_FILE_PATH "./test_null.log"

int	main (void)
{
	int		fd;
	char	*buf;

	fd = open (LOG_FILE_PATH, O_RDONLY);

	buf = "\n";
	while(ft_strchr(buf, '\n'))
	{
		buf = get_next_line(fd);
		printf("main: %s", buf);
		// free(buf);
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
