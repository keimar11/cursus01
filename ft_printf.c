/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitakah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:42:58 by keitakah          #+#    #+#             */
/*   Updated: 2022/12/12 15:43:03 by keitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cursus00/libft/libft.h"
#include <stdio.h>


int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			jdg(format[i + 1]);
			i += 2;
		}
		else
		{
			write (1, &format[i], 1);
		}
	}
	va_end(args);
}

int	main()
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
	ft_printf("I am %s.%c, %d years old born in %i, %u.\n", s, c, d, i, u);
	ft_printf("My birth date translated hexadecimal: November %xth, %X %%\n", x, X);
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