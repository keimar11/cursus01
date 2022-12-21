/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:41:43 by marvin            #+#    #+#             */
/*   Updated: 2022/11/12 19:16:16 by keitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if ((size_t)start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start + 1)
	{
		sub = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
		if (!sub)
			return (NULL);
		ft_strlcpy(sub, s + start, ft_strlen(s) - start + 1);
	}
	else
	{
		sub = (char *)malloc(sizeof(char) * (len + 1));
		if (!sub)
			return (NULL);
		ft_strlcpy(sub, s + start, len + 1);
	}
	return (sub);
}
