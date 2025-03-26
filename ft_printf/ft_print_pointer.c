/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomes- <togomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:11:21 by togomes-          #+#    #+#             */
/*   Updated: 2025/03/24 18:07:16 by togomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_pointer(unsigned long ptr)
{
	const char	*hexadigits = "0123456789abcdef";
	char		str[8 * sizeof(ptr) + 1];
	int			i;

	i = 0;
	if (ptr == 0)
	{
		ft_putchar_fd('0', 1);
		return ;
	}
	while (ptr > 0)
	{
		str[i++] = hexadigits[ptr % 16];
		ptr = ptr / 16;
	}
	while (--i >= 0)
		ft_putchar_fd(str[i], 1);
}

int	ft_print_pointer(void *pointer)
{
	unsigned long	ptr;
	size_t			count;

	ptr = (unsigned long)pointer;
	count = 0;
	if (!pointer)
		return (ft_print_string("(nil)"));
	ft_print_string("0x");
	count = 2;
	ft_put_pointer(ptr);
	while (ptr > 0)
	{
		count++;
		ptr = ptr / 16;
	}
	return (count);
}
