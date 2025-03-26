/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomes- <togomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:38:51 by togomes-          #+#    #+#             */
/*   Updated: 2024/10/26 15:33:40 by togomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*tmp_ptr;

	tmp_ptr = (char *) s;
	while (n > 0)
	{
		*(tmp_ptr++) = 0;
		n--;
	}
}
/*
int	main()
{
	char str[10] = "abcdefghi";
	printf("Value before call the function: %s.\n", str);
	ft_bzero(str, 4);
	printf("Value after call the function: %s.\n", str);
	return 0;
}*/