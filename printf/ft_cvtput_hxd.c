/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthxd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cui <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:47:25 by cui               #+#    #+#             */
/*   Updated: 2022/12/16 10:47:29 by cui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

void	ft_cvtput_hxd(int h)
{
	long int	nb;
	size_t		quo;
	size_t		rem;

	nb = (long int)h;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	quo = nb / 16;
	rem = nb % 16;
	if (nb >= 16)
	{
		ft_cvtput_hxd(quo);
		ft_cvtput_hxd(rem);
	}
	if (nb < 10)
		ft_putchar_fd('0' + nb, 1);
	else
		ft_putchar_fd('A' + (nb - 10), 1);
}