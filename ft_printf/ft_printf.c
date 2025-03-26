/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomes- <togomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:49:08 by togomes-          #+#    #+#             */
/*   Updated: 2025/03/24 18:07:22 by togomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_value(va_list args, char str)
{
	if (str == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	else if (str == 's')
		return (ft_print_string(va_arg(args, char *)));
	else if (str == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	else if (str == 'd' || str == 'i')
		return (ft_print_number(va_arg(args, int)));
	else if (str == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (str == 'x' || str == 'X')
		return (ft_print_hexa(va_arg(args, unsigned int), str));
	else if (str == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	if (!str)
		return (0);
	i = -1;
	len = 0;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
		else
			len = len + ft_convert_value(args, str[++i]);
	}
	va_end(args);
	return (len);
}
