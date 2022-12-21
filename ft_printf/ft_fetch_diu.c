/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fetch_diu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cui <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:16:55 by cui               #+#    #+#             */
/*   Updated: 2022/12/19 22:17:23 by cui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

int	ft_fetch_di(va_list ap)
{
	int	di;
	int	res;

	di = va_arg(ap, int);
	ft_putnbr_fd(di, 1);
	res = ft_digit(di);
	return (res);
}

int	ft_fetch_u(va_list ap)
{
	unsigned int	u;
	int				res;

	u = va_arg(ap, unsigned int);
	ft_putnbr_usgn(u);
	res = ft_digit_usgn(u);
	return (res);
}
