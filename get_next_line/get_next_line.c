/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cui <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:35:02 by cui               #+#    #+#             */
/*   Updated: 2022/12/29 22:29:15 by keitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_update_save(char *save, int fd)
{
	long long int	read_size;
	char			*read_passer;

	read_size = BUFFER_SIZE;
	while (!ft_strchr(save, '\n') && read_size == BUFFER_SIZE)
	{
		read_passer = (char *)malloc((BUFFER_SIZE + 1));
		if (!read_passer)
			return (free_string(save));
		read_size = read(fd, read_passer, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(read_passer);
			return (free_string(save));
		}
		read_passer[read_size] = '\0';
		save = ft_strjoin(save, read_passer);
		if (save == NULL)
			return (NULL);
		if (save[0] == '\0')
			return (free_string(save));
	}
	return (save);
}

size_t	get_next_size(char *save)
{
	size_t	next_size;

	next_size = 0;
	while (save[next_size] != '\n' && save[next_size] != '\0')
		next_size++;
	if (ft_strchr(save, '\n'))
		next_size++;
	return (next_size);
}

char	*get_output_line(char *save, size_t next_size)
{
	char	*output_line;

	output_line = (char *)malloc((next_size + 1));
	if (!output_line)
		return (free_string(save));
	ft_strlcpy(output_line, save, next_size + 1);
	return (output_line);
}

char	*get_update_save(char *save, size_t next_size)
{
	size_t	i;
	char	*update_save;

	update_save = (char *)malloc(ft_strlen(save) - next_size + 1);
	if (!update_save)
		return (free_string(save));
	i = 0;
	while (save[i + next_size])
	{
		update_save[i] = save[i + next_size];
		i++;
	}
	update_save[i] = '\0';
	free(save);
	return (update_save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	size_t		next_size;
	char		*output_line;

	if (fd < 0)
		return (NULL);
	if (save == NULL)
	{
		save = malloc(1);
		if (!save)
			return (NULL);
		save[0] = '\0';
	}
	save = read_update_save(save, fd);
	if (save == NULL)
		return (NULL);
	next_size = get_next_size(save);
	output_line = get_output_line(save, next_size);
	if (output_line == NULL)
		return (NULL);
	save = get_update_save(save, next_size);
	if (save == NULL)
		return (free_string(output_line));
	return (output_line);
}
