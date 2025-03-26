/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomes- <togomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:10:57 by togomes-          #+#    #+#             */
/*   Updated: 2025/03/24 19:59:51 by togomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "./libft/libft.h"

int		ft_printf(const char *format, ...);

int		ft_print_percent(void);
int		ft_print_pointer(void *pointer);
int		ft_print_hexa(unsigned int num, const char format);
int		ft_print_number(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_string(char *str);

void	ft_put_unsigned(unsigned int n);
void	ft_put_string(char *str);
int		ft_convert_value(va_list args, char str);
void	ft_put_pointer(unsigned long ptr);

#endif
