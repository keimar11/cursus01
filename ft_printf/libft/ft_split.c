/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_me.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 00:08:01 by marvin            #+#    #+#             */
/*   Updated: 2022/11/21 16:01:06 by keitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	arr_cnt(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			cnt++;
		i++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;
	size_t	save;

	if (!s)
		return (NULL);
	str = (char **)ft_calloc((arr_cnt(s, c) + 1), sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		save = i;
		while (s[i] != c && s[i] != 0)
			i++;
		str[j++] = ft_substr(s, save, i - save);
	}
	return (str);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	**arr;
// 	int		i;

// 	arr = ft_split(",,,hello,,,world,,,42,,,tokyo,,,,,,", ',');
// 	i = 0;
// 	while (arr[i] != 0)
// 	{
// 		printf("%s\n", arr[i]);
// 		i++;
// 	}
// 	free(arr);
// }
