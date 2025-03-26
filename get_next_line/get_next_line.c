/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomes- <togomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:55:30 by togomes-          #+#    #+#             */
/*   Updated: 2024/11/30 14:02:03 by togomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_str_per_line(char *buff)
{
	int		i;
	char	*str;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		str[i] = buff[i];
		i++;
	}
	if (buff[i] && buff[i] == '\n')
		str[i++] = '\n';
	return (str);
}

char	*ft_get_new_line(char *buff)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
		return (free(buff), NULL);
	str = ft_calloc((ft_strlen(buff) - i + 1), sizeof(*buff));
	if (!str)
		return (NULL);
	while (buff[++i])
		str[j++] = buff[i];
	str[j] = '\0';
	free(buff);
	return (str);
}

char	*ft_strjoin_and_clean(char *str, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(str, buffer);
	free(str);
	return (tmp);
}

char	*ft_read_first_line(char *str, int fd)
{
	char	*tmp;
	int		nbytes;

	if (!str)
		str = ft_calloc(1, 1);
	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	nbytes = 1;
	while (nbytes > 0)
	{
		nbytes = read(fd, tmp, BUFFER_SIZE);
		if (nbytes == -1)
			return (free(tmp), free(str), NULL);
		tmp[nbytes] = 0;
		str = ft_strjoin_and_clean(str, tmp);
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (free(tmp), str);
}

char	*get_next_line(int fd)
{
	char		*print_str;
	static char	*conc_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	conc_str = ft_read_first_line(conc_str, fd);
	if (!conc_str)
		return (NULL);
	print_str = ft_str_per_line(conc_str);
	conc_str = ft_get_new_line(conc_str);
	return (print_str);
}

/*
#include <fcntl.h>

int	main(void)
{
	int		fd = open("teste.txt", O_RDONLY);
	char	*line;

	if (fd == -1)
	{
		printf("Erro ao ler o ficheiro.\n");
		return (1);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close (fd);
	return (0);
}
*/
