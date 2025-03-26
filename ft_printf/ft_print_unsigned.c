/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomes- <togomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:57:36 by togomes-          #+#    #+#             */
/*   Updated: 2025/03/24 18:07:19 by togomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_unsigned(unsigned int n)
{
	if (n >= 10)
	{
		ft_put_unsigned(n / 10);
		ft_put_unsigned(n % 10);
	}
	else
		ft_putchar_fd(n + '0', 1);
}

int	ft_print_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	ft_put_unsigned(n);
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}
