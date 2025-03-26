/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomes- <togomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:42:59 by togomes-          #+#    #+#             */
/*   Updated: 2024/10/27 19:35:29 by togomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;

	srcsize = ft_strlen(src);
	if (srcsize + 1 < dstsize)
		ft_memcpy(dst, src, srcsize + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (srcsize);
}
/*
int	main()
{
	char	dst[12];
	char	src[] = "Hello?";
	size_t	dstsize = 12;
	size_t	srcsize = 0;
	printf("Value dst: %s\nValue src: %s\nSize dst: %zu\nSize src: %zu\n\n",\
	dst, src, dstsize,srcsize);
	srcsize = ft_strlcpy(dst,src,dstsize);
	printf("Value dst: %s\nValue src: %s\nSize dst: %zu\nSize src: %zu\n\n", \
	, src, dstsize,srcsize);
}*/
