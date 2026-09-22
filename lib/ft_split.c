/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 12:06:28 by adorofei          #+#    #+#             */
/*   Updated: 2026/08/22 11:29:02 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	ft_count_words(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static void	*free_split(char **splitted, size_t i)
{
	while (i > 0)
	{
		i--;
		free(splitted[i]);
	}
	free(splitted);
	return (NULL);
}

static char	*allocate_word(const char **str, char c)
{
	char	*word;
	size_t	len;
	size_t	i;

	len = 0;
	while ((*str)[len] && (*str)[len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = (*str)[i];
		i++;
	}
	word[i] = '\0';
	*str += len;
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**splitted;
	size_t	i;

	if (!s)
		return (NULL);
	splitted = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!splitted)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			splitted[i] = allocate_word(&s, c);
			if (!splitted[i])
				return (free_split(splitted, i));
			i++;
		}
		else
			s++;
	}
	splitted[i] = NULL;
	return (splitted);
}
