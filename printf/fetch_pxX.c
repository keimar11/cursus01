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

#include "libft.h"
#include "printf.h"

// void	fetch_p(va_list ap)
// {
// 	void	*ptr;

// 	ptr = va_arg(ap, void *);	//what return? hexadimical?
// 	//???
// }

void	fetch_x(va_list ap)
{
	int	x;
	char	*hex;

	x = va_arg(ap, int);
	ft_cvtput_hxd(x);
}

void	fetch_X(va_list ap)
{
	int	X;
	char	*hex;

	X = va_arg(ap, int);
	ft_cvtput_hxd(X);
}
