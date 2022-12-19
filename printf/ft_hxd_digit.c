/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hxd_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cui <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:47:25 by cui               #+#    #+#             */
/*   Updated: 2022/12/19 22:15:45 by cui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

void	ft_cvtput_hxd(uintptr_t n, int m)
{
	long int	nb;
	size_t		quo;
	size_t		rem;

	nb = (long int)n;
	quo = nb / 16;
	rem = nb % 16;
	if (nb >= 16)
	{
		ft_cvtput_hxd(quo, m);
		ft_cvtput_hxd(rem, m);
	}
	else if (nb >=10 && m == 1)
		ft_putchar_fd('a' + nb - 10, 1);
	else if (nb >= 10 && m == 0)
		ft_putchar_fd('A' + nb - 10, 1);
	else
		ft_putchar_fd('0' + nb, 1);
}

int	ft_digit_hxd(int n)
{
	long int	nb;
	int			d;

	if (n == 0)
		return (1);
	nb = (long int)n;
	d = 0;
	if (n < 0)
	{
		nb *= -1;
		d++;
	}
	while (nb)
	{
		nb /= 16;
		d++;
	}
	return (d);
}

int	ft_digit(int n)
{
	long int	nb;
	int			d;

	if (n == 0)
		return (1);
	nb = (long int)n;
	d = 0;
	if (n < 0)
	{
		nb *= -1;
		d++;
	}
	while (nb)
	{
		nb /= 10;
		d++;
	}
	return (d);
}
