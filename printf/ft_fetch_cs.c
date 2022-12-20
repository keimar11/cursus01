/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fetch_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cui <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:16:26 by cui               #+#    #+#             */
/*   Updated: 2022/12/19 22:17:02 by cui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

int	ft_fetch_c(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_fetch_s(va_list ap)
{
	char	*str;
	int		res;

	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	ft_putstr_fd(str, 1);
	res = ft_strlen(str);
	return (res);
}
// if() こわめ

int	ft_fetch_pct(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
