/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomes- <togomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:05:27 by togomes-          #+#    #+#             */
/*   Updated: 2024/10/27 20:02:09 by togomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	chr;

	chr = (unsigned char)c;
	while (*str != '\0')
	{
		if (*str == chr)
			return ((char *)str);
		str++;
	}
	if (chr == '\0')
		return ((char *) str);
	return (NULL);
}
