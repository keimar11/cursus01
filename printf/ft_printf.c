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

static void	which_one(char *format, char c)
{
	if (c == 'c')
	{
		va_arg(format, char);
	}
	if (c == 's')
	{
		va_arg(format, char *);
	}
	if (c == 'p')
	{
		va_arg(format, void *);
	}
	if (c == 'i')
	{
		va_arg(format, int);
	}
	if (c == 'u')
	{
		va_arg(format, unsigned int);
	}
	if (c == 'x')
	{
		va_arg(format, long int);
	}
	if (c == 'X')
	{
		va_arg(format, long int);
	}
	else
		ft_putchar_fd(1, c);
	return ;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	const char	*val;

	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			which_one(format, format[i + 1]);
			i++;
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