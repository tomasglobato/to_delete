/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomes- <togomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:24:58 by togomes-          #+#    #+#             */
/*   Updated: 2025/03/24 18:07:09 by togomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned int num, const char format)
{
	int		len;
	char	*hexa_digits;

	len = 0;
	if (format == 'x')
		hexa_digits = "0123456789abcdef";
	else if (format == 'X')
		hexa_digits = "0123456789ABCDEF";
	else
		return (0);
	if (num == 0)
		return (write(1, "0", 1));
	if (num >= 16)
		len += ft_print_hexa(num / 16, format);
	len = len + write(1, &hexa_digits[num % 16], 1);
	return (len);
}
