/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomes- <togomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:26:37 by togomes-          #+#    #+#             */
/*   Updated: 2024/10/29 13:26:37 by togomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp_ptr;
	size_t	i;

	i = count * size;
	tmp_ptr = malloc(i);
	if (!tmp_ptr)
		return (NULL);
	ft_memset(tmp_ptr, 0, i);
	return (tmp_ptr);
}
