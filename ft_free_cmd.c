/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:53:08 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/10 22:27:49 by degabrie         ###   ########.fr       */
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
