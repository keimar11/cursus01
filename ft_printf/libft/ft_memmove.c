/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 02:01:16 by marvin            #+#    #+#             */
/*   Updated: 2022/11/12 19:02:20 by keitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*str;
	unsigned char	*src;

	if (!(s1) && !(s2))
		return (NULL);
	str = (unsigned char *)s1;
	src = (unsigned char *)s2;
	if (s1 > s2)
	{
		str += n - 1;
		src += n - 1;
		while (n--)
			*str-- = *src--;
	}
	else
	{
		while (n--)
			*str++ = *src++;
	}
	return (s1);
}
