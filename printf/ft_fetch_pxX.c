/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fetch_pxX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cui <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:17:18 by cui               #+#    #+#             */
/*   Updated: 2022/12/19 22:17:29 by cui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

// %p は void * なので、64 bit 環境では
// uintptr_t 64 bitの整数型を16進数で出力する必要があります。

int	ft_fetch_p(va_list ap)
{
	uintptr_t	ptr;
	int			res;

	ptr = va_arg(ap, uintptr_t);
	ft_putstr_fd("0x", 1);
	ft_cvtput_hxd(ptr, 1);
	res = ft_digit_hxd(ptr);
	return (res);
}

int	ft_fetch_x(va_list ap)
{
	int	x;
	int	res;

	x = va_arg(ap, int);
	ft_cvtput_hxd(x, 1);
	res = ft_digit_hxd(x);
	return (res);
}

int	ft_fetch_X(va_list ap)
{
	int	X;
	int	res;

	X = va_arg(ap, int);
	ft_cvtput_hxd(X, 0);
	res = ft_digit_hxd(X);
	return (res);
}
