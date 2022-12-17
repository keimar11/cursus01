/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_pxX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cui <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:17:18 by cui               #+#    #+#             */
/*   Updated: 2022/12/16 11:17:41 by cui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

void	fetch_p(va_list ap)
{
	unsigned long long	ptr;

	ptr = va_arg(ap, unsigned long long);
	ft_putstr_fd("0x10", 1);
	ft_cvtput_hxd(ptr, 1);
}

void	fetch_x(va_list ap)
{
	int	x;
	char	*hex;

	x = va_arg(ap, int);
	ft_cvtput_hxd(x, 1);
}

void	fetch_X(va_list ap)
{
	int	X;
	char	*hex;

	X = va_arg(ap, int);
	ft_cvtput_hxd(X, 0);
}
