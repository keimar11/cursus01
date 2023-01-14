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
