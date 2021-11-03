/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:45:06 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/03 15:45:19 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*ptr;
	size_t	size;
	size_t	len;
	size_t	i;

	if (!s1)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = (char *)malloc(size * sizeof(char));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
	i = 0;
	len = ft_strlen(s1);
	while (i < size - len - 1 && s2[i])
	{
		ptr[len + i] = s2[i];
		i++;
	}
	ptr[len + i] = '\0';
	free(s1);
	return (ptr);
}
