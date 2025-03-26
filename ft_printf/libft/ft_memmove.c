/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomes- <togomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:31:36 by togomes-          #+#    #+#             */
/*   Updated: 2024/10/27 19:07:06 by togomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*temp_dst;
	const char	*temp_src;

	if (!dst && !src)
		return (NULL);
	temp_dst = dst;
	temp_src = src;
	if (temp_dst < temp_src)
		while (len--)
			*temp_dst++ = *temp_src++;
	else
	{
		temp_dst += len;
		temp_src += len;
		while (len--)
			*(--temp_dst) = *(--temp_src);
	}
	return (dst);
}
