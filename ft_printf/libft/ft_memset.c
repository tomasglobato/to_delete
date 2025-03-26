/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomes- <togomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:11:07 by togomes-          #+#    #+#             */
/*   Updated: 2024/10/26 16:52:32 by togomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp_ptr;

	tmp_ptr = b;
	while (len > 0)
	{
		*tmp_ptr++ = (unsigned char) c;
		len--;
	}
	return (b);
}
/*
int	main()
{
	char str[10] = "abcdefghi";

	ft_memset(str, 'A', 4);
	printf("%s\n", str);
	return 0;
}*/