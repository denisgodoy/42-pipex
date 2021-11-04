/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 04:17:37 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/04 05:03:39 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

static size_t	ft_count_words(char const *s, char c);
static size_t	ft_substr_len(char const *s, char c);

static void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	str = b;
	while (len--)
		*(str++) = (unsigned char)c;
	return (b);
}

static void	ft_bzero(void *s, size_t n)
{
	if (n > 0)
		ft_memset(s, 0, n);
}

static void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	tab = (char **)ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
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