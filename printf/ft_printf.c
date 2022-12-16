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

#include "libft.h"
#include "printf.h"
#include <stdio.h>

int ft_printf(const char *format, ...)
{
	va_list ap;
	size_t  i;
	const char  *val;

	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			fetch_which (ap, format[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
		}
		i++;
	}
	va_end(ap);
	return (1);
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
	printf("I am %s.%c, %d years old born in %i, %u.\n", s, c, d, i, u);
	printf("My birth date translated hexadecimal: November %xth, %X %%\n", x, X);
	return (0);
}

// I am Keito.T, 17 years old born in -17, 2005.
// My birth date translated hexadecimal: November 18th, 7D5 %

// %c Prints a single character.
// %s Prints a string (as defined by the common C convention).
// %p The void * pointer argument has to be printed in hexadecimal format.
// %d Prints a decimal (base 10) number.
// %i Prints an integer in base 10.
// %u Prints an unsigned decimal (base 10) number.
// %x Prints a number in hexadecimal (base 16) lowercase format.
// %X Prints a number in hexadecimal (base 16) uppercase format.
// %% Prints a percent sign.
