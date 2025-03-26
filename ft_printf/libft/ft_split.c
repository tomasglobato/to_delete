/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomes- <togomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:49:28 by togomes-          #+#    #+#             */
/*   Updated: 2024/10/30 15:49:28 by togomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(const char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*get_next_word(const char *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_split(char **words)
{
	int	i;

	if (!words)
		return ;
	i = 0;
	while (words[i] != NULL)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

static char	**ft_allocate(char **words, char const *s, int count, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < count)
	{
		if (s[i] != c)
		{
			words[j] = get_next_word(&s[i], c);
			if (!words[j])
			{
				free_split(words);
				return (NULL);
			}
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	words[j] = NULL;
	return (words);
}

char	**ft_split(const char *s, char c)
{
	int		count;
	char	**words;

	if (!s)
		return (NULL);
	count = ft_word_count(s, c);
	words = (char **)malloc(sizeof(char *) * (count + 1));
	if (!words)
		return (NULL);
	return (ft_allocate(words, s, count, c));
}
/*int main(void)
{
    const char *str = "Hello world! This is a test.";
    char delimiter = ' ';
    char **result;
    int i = 0;

    // Chama a função ft_split
    result = ft_split(str, delimiter);

    // Verifica se a função retornou NULL
    if (!result)
    {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    // Imprime os resultados
    while (result[i] != NULL)
    {
        printf("Palavra %d: %s\n", i, result[i]);
        free(result[i]); // Liberta a memória de cada palavra
        i++;
    }
    free(result); // Liberta a memória do array de palavras

    return 0;
}
*/
