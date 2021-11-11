/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:27:59 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/10 22:28:08 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

void	ft_free_path(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (pipex->src.path[++i])
		free(pipex->src.path[i]);
	free(pipex->src.path);
	return ;
}
