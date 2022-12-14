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

static void	which_one(char c)
{
	if (c == 'c');
	if (c == 's');
	if (c == 'p');
	if (c == 'i');
	if (c == 'u');
	if (c == 'x');
	if (c == 'X');
	if (c == '%');
}

static size_t	one_or_not(char *format)
{
	size_t	i;
	char	*stack;

	i = 0;
	stack = "cspdiuxX%";
	while (format[i])
	{
		if (ft_strchr(stack, format[i]))
		{
			which_one(format[i]);
		}
		i++;
	}
	
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	va_list	cp;
	size_t	i;
	const char	*val;

	va_start(ap, format);
	va_copy(cp, ap);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i += jdg(&format[i + 1]);
		}
		else
		{
			write (1, &format[i], 1);
		}
		i++;
	}
	va_end(ap);
	return ;
}

int	main()
{
	char c;
	char *s;
	int d, i, x, X;
	unsigned int u;
	int mynumber;

	s = "Keito";
	c = 'T';
	d = 17;
	i = -17;
	u = 2005;
	x = 24;
	X = 2005;
	printf("I am %s.%c, %d years old born in %i, %u.\n", s, c, d, i, u);
	printf("My birth date translated hexadecimal: November %xth, %X %%\n", x, X);

	mynumber = printf("%%%%%%%%");
	printf("%i", mynumber);
	mynumber = "I am 11";
	printf("\n%d", mynumber);
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