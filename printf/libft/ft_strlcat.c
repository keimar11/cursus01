/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 00:49:02 by marvin            #+#    #+#             */
/*   Updated: 2022/11/08 23:03:23 by keitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dl;
	size_t	sl;

	sl = ft_strlen (src);
	if (!dst && dstsize == 0)
		return (sl);
	dl = ft_strlen (dst);
	if (dl >= dstsize)
		return (sl + dstsize);
	dst += dl;
	ft_strlcpy (dst, src, dstsize - dl);
	return (dl + sl);
}

// dstsize: size of dst to be located == size we're able to access
// dst = NULL => Segmentation fault;
// ?Needless to return or to return (sizeof(sl));
// I think we have to return (sl);
// ?#25 return(sl + dstsize) or (dstsize);
