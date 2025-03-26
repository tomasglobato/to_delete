/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomes- <togomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:49:03 by togomes-          #+#    #+#             */
/*   Updated: 2024/11/10 10:54:40 by togomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_count_int(long n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nbr;

	nbr = (long)n;
	len = ft_count_int(nbr);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr == 0)
		str[0] = '0';
	else if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		str[--len] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (str);
}

/*
int	main()
{
	int		num = 22312312312312300;
	char	*str;
	str = ft_itoa(num);
	printf("O número %d em string fica: %s\n", num, str);
	return (0);
}*/
