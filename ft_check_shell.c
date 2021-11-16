/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_shell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:08:30 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/15 23:08:56 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

char	*ft_check_shell(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (pipex->src.envp[++i])
	{
		if (!ft_memcmp(pipex->src.envp[i], "SHELL", 5))
			return (ft_strjoin(ft_strrchr(pipex->src.envp[i], '/') + 1, ": "));
	}
	return (0);
}
