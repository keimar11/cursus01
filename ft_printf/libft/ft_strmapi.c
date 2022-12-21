/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 23:36:51 by marvin            #+#    #+#             */
/*   Updated: 2022/11/12 19:50:32 by keitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*array;
	size_t	strl;
	size_t	i;

	if (!s || !f)
		return (NULL);
	strl = ft_strlen(s);
	array = (char *)malloc(sizeof(char) * (strl + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (i < strl)
	{
		array[i] = (*f)(i, s[i]);
		i++;
	}
	array[i] = '\0';
	return (array);
}
