/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitakah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:42:58 by keitakah          #+#    #+#             */
/*   Updated: 2022/12/20 22:38:40 by keitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	size_t	res;

	va_start(ap, format);
	i = 0;
	res = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			res += ft_fetch_which (ap, format[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			res++;
		}
		i++;
	}
	va_end(ap);
	return (res);
}

/*
int	main(void)
{
	int	or;
	int	ft;

	or = printf(" %p %p ", 0, 0);
	printf("orig: %d\n", or);
	ft = ft_printf(" %p %p ", 0, 0);
	ft_printf("mine: %d", ft);
}
*/
