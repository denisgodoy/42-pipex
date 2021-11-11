/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:53:08 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/10 22:58:01 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

void	ft_free_cmd(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (pipex->cmd[++i])
		free(pipex->cmd[i]);
	free(pipex->cmd);
	return ;
}

void	ft_free_path(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (pipex->src.path[++i])
		free(pipex->src.path[i]);
	free(pipex->src.path);
	return ;
}

void	ft_free_src(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (pipex->src.cmd[++i])
		free(pipex->src.cmd[i]);
	free(pipex->src.cmd);
	return ;
}
