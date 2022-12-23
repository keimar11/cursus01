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

char *get_next_line(int fd)
{
	static char	*save;
	char		*read_passer;
	size_t		read_size;
	size_t		end_of_size;
	char		*get_line;
	size_t		get_size;

	save = (char *)malloc(sizeof(char));
	if (!save)
		return (NULL);
	save[0] = '\0';
	while (!ft_strchar(save, '\n') && !ft_strchar(save, EOF))
	{
		read_passer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!read_passer)
			return (NULL);
		read_size = read(fd, read_passer, BUFFER_SIZE);
		read_passer[read_size] = '\0';
		save = ft_strjoin(save, read_passer);
		free(read_passer);
	}
	end_of_size = 1;
	if (ft_strchar(save, '\n'))
		end_of_size = 2;
	get_size = 0;
	while (save[get_size] != '\n' && save[get_size] != '\0')
		get_size++;
	get_line = (char *)malloc(sizeof(char) * (get_size + end_of_size));
	if (!get_line)
		return (NULL);
	ft_strlcpy(get_line, save, get_size + end_size);
	free(save);
	return (get_line);
}

// static char *save => NULL initialization