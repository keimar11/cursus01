/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 23:39:34 by marvin            #+#    #+#             */
/*   Updated: 2022/11/14 00:24:40 by keitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	size_t		quo;
	size_t		rem;

	nb = (long int)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	quo = nb / 10;
	rem = nb % 10;
	if (nb >= 10)
	{
		ft_putnbr_fd(quo, fd);
		ft_putnbr_fd(rem, fd);
	}
	else
		ft_putchar_fd('0' + rem, fd);
}
