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

#include "../cursus00/libft/libft.h"
#include <stdio.h>

static void	fetch_c(va_list ap)
{
	char	c;

	c = va_arg(ap, char);
	write (1, c, 1);
}

static void	fetch_s(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	ft_putstr_fd(str, 1);
}

static void	fetch_p(va_list ap)
{
	void	*ptr;

	ptr = va_arg(ap, void *);
	ft_putnbr_fd(ptr, 1);
}

static void	fetch_di(va_list ap)
{
	int	di;

	di = va_arg(ap, int);
	ft_putnbr_fd(di, 1);
}

static void	fetch_u(va_list ap)
{
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	ft_putnbr_fd(u, 1);
}

static void	fetch_x(va_list ap)
{
	int	x;
	char	*hex;

	x = va_arg(ap, int);
	hex = cvt_hexadecimal(x);
	ft_putstr_fd(x, 1);
}

static void	fetch_X(va_list ap)
{
	int	X;
	char	*hex;

	X = va_arg(ap, int);
	hex = cvt_hexadecimal(X);
	ft_putstr_fd(X, 1);
}

static void which_one(va_list ap, char c)
{
	if (c == 'c')
	{
		va_arg(ap, char);
	}
	if (c == 's')
	{
		va_arg(ap, char *);
	}
	if (c == 'p')
	{
		va_arg(ap, void *);
	}
	if (c == 'd', c == 'i')
	{
		va_arg(ap, int);
	}
	if (c == 'u')
	{
		va_arg(ap, unsigned int);
	}
	if (c == 'x')
	{
		va_arg(ap, long int);
	}
	if (c == 'X')
	{
		va_arg(ap, long int);
	}
	else
		ft_putchar_fd(1, c);
	return ;
}

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
			which_one(ap, format[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd (1, format[i]);
		}
		i++;
	}
	va_end(ap);
	return ;
	}

	int main()
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
