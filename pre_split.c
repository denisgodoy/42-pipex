/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:23:33 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/14 16:27:52 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

static char	*ft_strtrim(char const *s1, char const *set);
static char	*ft_strchr(const char *s, int c);

int	ft_pre_split(t_pipex *pipex, char *cmd, int arg)
{
	int	i;
	int	j;

	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == '\'')
		{
			j = i + 1;
			while (cmd[j] != '\'')
			{
				if (cmd[j] == ' ')
					pipex->cmd[arg][j] = '`';
				j++;
			}
			return (1);
		}
	}
	return (0);
}

void	ft_update_char(t_pipex *pipex)
{
	int		i;
	int		j;
	char	*temp;

	i = -1;
	while (pipex->src.cmd[++i])
	{
		j = -1;
		while (pipex->src.cmd[i][++j])
		{
			if (pipex->src.cmd[i][j] == '`')
			{
				while (pipex->src.cmd[i][j] == '`')
				{
					pipex->src.cmd[i][j] = ' ';
					j++;
				}
				temp = ft_strdup(pipex->src.cmd[i]);
				free(pipex->src.cmd[i]);
				pipex->src.cmd[i] = ft_strtrim(temp, "\'");
				free(temp);
				return ;
			}
		}
	}
}

static char	*ft_strchr(const char *s, int c)
{
	char	*nb;

	nb = (char *)&s[(ft_strlen(s))];
	if ((char)c == '\0')
		return (nb);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}

static char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*ptr;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	ptr = ft_substr(s1, 0, i + 1);
	if (!ptr)
		return (0);
	return (ptr);
}
