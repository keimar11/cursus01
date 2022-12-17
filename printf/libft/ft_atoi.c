/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 01:29:37 by marvin            #+#    #+#             */
/*   Updated: 2022/11/18 00:11:18 by cui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*overflow(long int n, const char c)
{
	long int	jdg1;
	long int	jdg2;

	jdg1 = LONG_MAX / 10;
	jdg2 = LONG_MAX % 10;
	if (n > jdg1)
		return (NULL);
	if (n == jdg1 && c - 48 > jdg2)
		return (NULL);
	return ("safe");
}

static char	*underflow(long int n, const char c)
{
	long int	jdg1;
	long int	jdg2;

	jdg1 = LONG_MIN / 10;
	jdg2 = LONG_MIN % 10;
	if (n < jdg1)
		return (NULL);
	if (n == jdg1 / 10 && (c - 48) * (-1) < jdg2)
		return (NULL);
	return ("safe");
}

int	ft_atoi(const char *str)
{
	int			m;
	long int	nb;

	m = 1;
	nb = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			m *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (m > 0 && overflow(nb, *str) == NULL)
			return ((int)LONG_MAX);
		if (m < 0 && underflow(-1 * nb, *(str + 1)) == NULL)
			return ((int)LONG_MIN);
		nb = nb * 10 + (*str++ - '0');
	}
	return (m * nb);
}
