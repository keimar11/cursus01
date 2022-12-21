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

void	ft_putnbr_hxd(uintptr_t n, int m)
{
	size_t		quo;
	size_t		rem;

	quo = n / 16;
	rem = n % 16;
	if (n >= 16)
	{
		ft_putnbr_hxd(quo, m);
		ft_putnbr_hxd(rem, m);
	}
	else if (n >= 10 && m == 1)
		ft_putchar_fd('a' + n - 10, 1);
	else if (n >= 10 && m == 0)
		ft_putchar_fd('A' + n - 10, 1);
	else
		ft_putchar_fd('0' + n, 1);
}

int	ft_digit_hxd(uintptr_t n)
{
	int			d;

	if (n == 0)
		return (1);
	d = 0;
	while (n)
	{
		n /= 16;
		d++;
	}
	return (d);
}

void	ft_putnbr_usgn(unsigned int n)
{
	size_t		quo;
	size_t		rem;

	quo = n / 10;
	rem = n % 10;
	if (n >= 10)
	{
		ft_putnbr_usgn(quo);
		ft_putnbr_usgn(rem);
	}
	else
		ft_putchar_fd('0' + rem, 1);
}

int	ft_digit_usgn(unsigned int n)
{
	int	d;

	if (n == 0)
		return (1);
	d = 0;
	while (n)
	{
		n /= 10;
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
