/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:53:08 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/08 20:59:24 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

void	ft_free_cmd(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd[i])
		free(pipex->cmd[i++]);
	free(pipex->cmd);
	return ;
}

void	ft_free_path(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->utils.path[i])
		free(pipex->utils.path[i++]);
	free(pipex->utils.path);
	return ;
}
