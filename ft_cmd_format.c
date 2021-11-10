/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 22:38:24 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/10 16:48:16 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

void	ft_cmd_format(t_pipex *pipex)
{
	int	i;
	int	j;

	pipex->src.cmd = (char **)malloc((pipex->src.cmdlen + 1) * sizeof(char *));
	if (!pipex->src.cmd)
	{
		ft_free_cmd(pipex);
		ft_free_path(pipex);
		unlink(pipex->outfile);
		perror(strerror(ENOMEM));
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (pipex->cmd[++i])
	{
		j = -1;
		while (pipex->cmd[i][++j])
			if (pipex->cmd[i][j] == ' ')
				break ;
		pipex->src.cmd[i] = ft_substr(pipex->cmd[i], 0, j);
	}
	pipex->src.cmd[i] = NULL;
	return ;
}
