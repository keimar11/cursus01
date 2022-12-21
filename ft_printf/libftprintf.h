/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cui <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:47:40 by cui               #+#    #+#             */
/*   Updated: 2022/12/16 11:47:44 by cui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <inttypes.h>

int		ft_printf(const char *format, ...);
int		ft_fetch_c(va_list ap);
int		ft_fetch_s(va_list ap);
int		ft_fetch_p(va_list ap);
int		ft_fetch_di(va_list ap);
int		ft_fetch_u(va_list ap);
int		ft_fetch_x(va_list ap);
int		ft_fetch_large_x(va_list ap);
int		ft_fetch_pct(void);
int		ft_fetch_which(va_list ap, char c);
int		ft_digit(int n);
int		ft_digit_usgn(unsigned int n);
int		ft_digit_hxd(uintptr_t n);
void	ft_putnbr_usgn(unsigned int n);
void	ft_putnbr_hxd(uintptr_t n, int m);

#endif