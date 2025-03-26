/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomes- <togomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:31:42 by togomes-          #+#    #+#             */
/*   Updated: 2024/10/27 19:41:12 by togomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*last;

	last = NULL;
	while (*str != '\0')
	{
		if (*(unsigned char *)str == (unsigned char)c)
			last = ((char *)str);
		str++;
	}
	if (*(unsigned char *)str == (unsigned char)c)
		return ((char *)str);
	return (last);
}
