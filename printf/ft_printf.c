/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitakah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:42:58 by keitakah          #+#    #+#             */
/*   Updated: 2022/12/16 10:29:08 by cui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"
#include <stdio.h>

int ft_printf(const char *format, ...)
{
	va_list ap;
	size_t  i;
	size_t	res;

	va_start(ap, format);
	i = 0;
	res = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			res = ft_fetch_which (ap, format[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
		}
		i++;
		res++;
	}
	va_end(ap);
	return (res);
}

int main()
{
	char c;
	char *s;
	int d, i, x, X;
	unsigned int u;

	s = "Keito";
	c = 'T';
	d = 17;
	i = -17;
	u = 2005;
	x = 24;
	X = 2005;

	printf("Here is Mine:\n");
	ft_printf("\tI am %s.%c, %d years old born in %i, %u. Located %p%%\n", s, c, d, i, u, s);
	ft_printf("\tMy birth date translated hexadecimal: November %xth, %X%%\n", x, X);

	printf("Here is Ans:\n");
	printf("\tI am %s.%c, %d years old born in %i, %u. Located %p%%\n", s, c, d, i, u, s);
	printf("\tMy birth date translated hexadecimal: November %xth, %X%%\n", x, X);
	printf("%p\n", NULL);

	return (0);
}

// I am Keito.T, 17 years old born in -17, 2005. Located 0x105942f2e%
// My birth date translated hexadecimal: November 18th, 7D5%

// %c Prints a single character.
// %s Prints a string (as defined by the common C convention).
// %p The void * pointer argument has to be printed in hexadecimal format.
// %d Prints a decimal (base 10) number.
// %i Prints an integer in base 10.
// %u Prints an unsigned decimal (base 10) number.
// %x Prints a number in hexadecimal (base 16) lowercase format.
// %X Prints a number in hexadecimal (base 16) uppercase format.
// %% Prints a percent sign.
