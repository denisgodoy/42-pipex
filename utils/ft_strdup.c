/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:45:25 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/03 15:45:51 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	size;

	size = ft_strlen(s1) + 1;
	ptr = (char *)malloc(size * sizeof(char));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s1, size);
	return (ptr);
}
