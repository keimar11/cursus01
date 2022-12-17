/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 01:53:06 by marvin            #+#    #+#             */
/*   Updated: 2022/11/12 18:48:24 by keitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	ll;

	if (!big && len == 0)
		return (NULL);
	if (*little == '\0' && (*big == '\0' || len == 0))
		return ((char *)big);
	ll = ft_strlen(little);
	k = 0;
	while (*big && k < len)
	{
		i = 0;
		j = k;
		while (big[i] == little[i] && big[i] != '\0' && j++ < len)
			i++;
		if (i == ll)
			return ((char *)big);
		big++;
		k++;
	}
	return (NULL);
}
