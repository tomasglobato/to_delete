/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomes- <togomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:23:10 by togomes-          #+#    #+#             */
/*   Updated: 2025/03/24 23:12:19 by togomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_error(char *s, ...)
{
	va_list	args;

	va_start(args, s);
	ft_printf("Error\n");
	ft_printf(s, args);
	va_end(args);
	exit(1);
}

void	input_error(char *s, ...)
{
	va_list	args;

	va_start(args, s);
	ft_printf("Error\n");
	ft_printf(s, args);
	va_end(args);
	exit(1);
}
