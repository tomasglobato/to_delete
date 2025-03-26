/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomes- <togomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:50:39 by togomes-          #+#    #+#             */
/*   Updated: 2024/11/05 23:00:41 by togomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char nb, int fd)
{
	write(fd, &nb, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	i;

	i = n;
	if (i < 0)
	{
		ft_putchar('-', fd);
		i *= -1;
	}
	if (i >= 10)
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putnbr_fd(i % 10, fd);
	}
	else
	{
		ft_putchar(i + '0', fd);
	}
}
