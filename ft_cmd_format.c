/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 22:38:24 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/08 21:01:56 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

void	ft_cmd_format(t_pipex *pipex)
{
	int	i;
	int	j;

	pipex->utils.cmd = (char **)malloc((pipex->utils.cmd_len + 1) * sizeof(char *));
	if (!pipex->utils.cmd)
	{
		ft_free_cmd(pipex);
		ft_free_path(pipex);
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (pipex->cmd[++i])
	{
		j = -1;
		while (pipex->cmd[i][++j])
			if (pipex->cmd[i][j] == ' ')
				break ;
		pipex->utils.cmd[i] = ft_substr(pipex->cmd[i], 0, j);
		printf("%s\n", pipex->cmd[i]);
		if (access("/usr/bin/cut", X_OK) < 0)
		{
			perror("-bash");
			exit(EXIT_FAILURE);
		}
	}
	pipex->utils.cmd[i] = NULL;
	return ;
}
