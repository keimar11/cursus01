/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cui <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:16:55 by cui               #+#    #+#             */
/*   Updated: 2022/12/16 11:17:00 by cui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

void	fetch_di(va_list ap)
{
	int	di;

	di = va_arg(ap, int);
	ft_putnbr_fd(di, 1);
}

void	fetch_u(va_list ap)
{
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	ft_putnbr_fd(u, 1);
}
