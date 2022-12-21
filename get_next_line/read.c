#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define LOG_FILE_PATH "./test"

static ssize_t	my_read (int fd, char *buf, size_t size)
{
	ssize_t	done = 0;
	size_t	s = size;

	while (s > 0)
	{
		done = read (fd, (void *)buf, s);

		if (done < 0)
		{
			if (errno == EINTR)				/* Interrupt */
				continue;
			else							/* Error */
				return (done);
		}
		else if (done == 0)					/* EOF */
		{
			return (size - s);
		}
		else
		{
			buf += done;
			s -= done;
		}
	}
	return (size);
}

int	main (void)
{
	int		fd, size;
	char	buf[128];

	fd = open (LOG_FILE_PATH, O_RDONLY);

	if (fd < 0)
		return -1;

	size = my_read (fd, buf, BUFFER_SIZE);
	if (size != BUFFER_SIZE) 
	{
		close (fd);
		return (-1);
	}

	/* 処理を書く */

	close (fd);
	return (0);
}
