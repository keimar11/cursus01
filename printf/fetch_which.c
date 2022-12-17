/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cui <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:47:43 by cui               #+#    #+#             */
/*   Updated: 2022/12/16 10:47:46 by cui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

void fetch_which(va_list ap, char c)
{
	if (c == 'c')
		fetch_c(ap);
	else if (c == 's')
		fetch_s(ap);
	else if (c == 'p')
		fetch_p(ap);
	else if (c == 'd'|| c == 'i')
		fetch_di(ap);
	else if (c == 'u')
		fetch_u(ap);
	else if (c == 'x')
		fetch_x(ap);
	else if (c == 'X')
		fetch_X(ap);
	else
	{
		ft_putchar_fd('%', 1);
		if (c == '%')
			return ;
		ft_putchar_fd(c, 1);
	}
	return ;
}
