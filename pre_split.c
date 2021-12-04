/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:23:33 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/04 20:24:26 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

int	ft_pre_split(t_pipex *pipex, char *cmd, int arg)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'' && cmd[i + 2] == '\'')
		{
			pipex->cmd[arg][i + 1] = '`';
			return (i);
		}
		i++;
	}
	return (0);
}

void	ft_update_char(t_pipex *pipex)
{
	int	i;
	int	j;

	i = -1;
	while (pipex->src.cmd[++i])
	{
		j = -1;
		while (pipex->src.cmd[i][++j])
		{
			if (pipex->src.cmd[i][j] == '`')
			{
				free(pipex->src.cmd[i]);
				pipex->src.cmd[i] = ft_strdup(" ");
				return ;
			}
		}
	}
}
