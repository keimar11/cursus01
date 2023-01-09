/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitakah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:07:25 by keitakah          #+#    #+#             */
/*   Updated: 2023/01/09 12:07:27 by keitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"
#define LOG_FILE_PATH "test/test_ko.log"

int	main(void)
{
	int		fd;
	char	*buf;

	fd = open (LOG_FILE_PATH, O_RDONLY);
	buf = "\n";
	while (ft_strchr(buf, '\n') && buf != NULL)
	{
		buf = get_next_line(fd);
		printf("%s", buf);
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
