/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cui <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:35:25 by cui               #+#    #+#             */
/*   Updated: 2022/12/21 12:35:27 by cui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*read_update_save(char *save, int fd);
size_t	get_next_size(char *save);
char	*get_output_line(char *save, size_t next_size);
char	*get_update_save(char *save, size_t next_size);
char	*free_save(char *save);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif