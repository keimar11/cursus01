/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fetch_which.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cui <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:47:43 by cui               #+#    #+#             */
/*   Updated: 2022/12/19 22:16:34 by cui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

int	ft_fetch_which(va_list ap, char c)
{
	int	res;

	if (c == 'c')
		res = ft_fetch_c(ap);
	else if (c == 's')
		res = ft_fetch_s(ap);
	else if (c == 'p')
		res = ft_fetch_p(ap);
	else if (c == 'd' || c == 'i')
		res = ft_fetch_di(ap);
	else if (c == 'u')
		res = ft_fetch_u(ap);
	else if (c == 'x')
		res = ft_fetch_x(ap);
	else if (c == 'X')
		res = ft_fetch_large_x(ap);
	else if (c == '%')
		res = ft_fetch_pct();
	else
	{
		ft_putchar_fd('%', 1);
		ft_putchar_fd(c, 1);
		res = 2;
	}
	return (res);
}
