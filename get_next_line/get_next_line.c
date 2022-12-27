/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cui <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:35:02 by cui               #+#    #+#             */
/*   Updated: 2022/12/21 12:35:10 by cui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_update_save(char *save, int fd)
{
	static size_t	read_size;
	char			*read_passer;
	char			*tmp;

	if (save == NULL)
	{
		save = malloc(1);
		if (!save)
			return (NULL);
		save[0] = '\0';
	}
	read_size = BUFFER_SIZE;
	while (!ft_strchr(save, '\n') && read_size >= BUFFER_SIZE)
	{
		read_passer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!read_passer)
			return (NULL);
		read_size = read(fd, read_passer, BUFFER_SIZE);
		read_passer[read_size] = '\0';
		tmp = ft_strjoin(save, read_passer);
		free(read_passer);
	}
	// free(save);
	return (tmp);
}
// saveが1コ以上\nを持っている


char	*get_next_line(int fd)
{
	static char	*save;
	size_t	end_size;
	size_t	get_next_size;
	char	*get_next_line;

	save = read_update_save(save, fd);
	if (ft_strchr(save, '\n'))
		end_size = 2;
	else
		end_size = 1;
	get_next_size = 0;
	while (save[get_next_size] != '\n' && save[get_next_size] != '\0')
		get_next_size++;
	get_next_line = (char *)malloc(sizeof(char) * (get_next_size + end_size));
	if (!get_next_line)
		return (NULL);
	ft_strlcpy(get_next_line, save, get_next_size + end_size);
	save += get_next_size + end_size - 1;
	return (get_next_line);
}

// read(fd, buf, BUFFER_SIZE) : CONST
// static initialization : never initialize. 0 or '\0' or NULL initialized at the same time as declaration.
// read to EOF : read_size < BUFFER_SIZE
// gnl has EOF : !ft_strchr(save, '\n')
// after get nl, save has to rm str of nl because we wanna output from next to last nl.

/*
memory must be freed
	save:
	get_next_line:
	read_passer: OK
*/