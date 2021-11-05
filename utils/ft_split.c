/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 04:17:37 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/04 22:26:47 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

static size_t	ft_count_words(char const *s, char c);
static size_t	ft_substr_len(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	tab = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			tab[j] = ft_substr(s, i, ft_substr_len(s + i, c));
			i = (i + ft_substr_len(s + i, c) - 1);
			j++;
		}
		i++;
	}
	tab[j] = NULL;
	return (tab);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 1;
	words = 0;
	while (*s)
	{
		if (*s == c)
			i = 1;
		else if (i == 1)
		{
			i = 0;
			words++;
		}
		s++;
	}
	return (words);
}

static size_t	ft_substr_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}
