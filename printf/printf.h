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

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>

void	ft_cvtput_hxd(int h, int m);
void	fetch_c(va_list ap);
void	fetch_s(va_list ap);
void	fetch_p(va_list ap);
void	fetch_di(va_list ap);
void	fetch_u(va_list ap);
void	fetch_x(va_list ap);
void	fetch_X(va_list ap);
void	fetch_which(va_list ap, char c);

#endif