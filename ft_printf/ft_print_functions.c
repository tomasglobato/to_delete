/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomes- <togomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:57:22 by togomes-          #+#    #+#             */
/*   Updated: 2025/03/24 18:07:13 by togomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
}

int	ft_print_string(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_put_string("(null)");
		return (6);
	}
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_number(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_print_string(num);
	free(num);
	return (len);
}

int	ft_print_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
