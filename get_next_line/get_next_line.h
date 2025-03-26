/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomes- <togomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:55:22 by togomes-          #+#    #+#             */
/*   Updated: 2025/03/24 19:48:23 by togomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "../ft_printf/libft/libft.h"

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
char	*ft_read_first_line(char *str, int fd);
char	*ft_str_per_line(char *buff);
char	*ft_get_new_line(char *buff);

#endif
