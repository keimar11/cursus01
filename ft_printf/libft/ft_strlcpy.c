/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 01:52:46 by marvin            #+#    #+#             */
/*   Updated: 2022/11/09 19:45:05 by keitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	sl;

	sl = ft_strlen(src);
	if (!dst || size == 0)
		return (sl);
	while (size-- > 1 && *src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (sl);
}

/*
#include <stdio.h>
#include <string.h>
int	main()
{
	char s1[] = "aaaaa";
	const char *s2 = "bb";
	char dst1[20];
	char dst2[20];
	const char *src = "";

	printf("%lu\n", sizeof(s1));
	return 0;
	strlcpy(s1, s2, sizeof(s1));
	printf("%s\n", s1+2);
	return 0;
	memset(dst1, 'a', sizeof(dst1));
	memset(dst2, 'a', sizeof(dst2));
	ft_strlcpy(dst1, src, sizeof(dst1));
	printf("%s\n", dst1 + 1);
	strlcpy(dst2, src, sizeof(dst2));
	printf("%s\n", dst2 + 1);
}
*/
