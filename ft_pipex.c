/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:05:39 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/08 21:31:30 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

void	ft_pipex(t_pipex *pipex, char **argv, char **envp)
{
	printf("ag1 %s\nenv2 %s\nout %s\n", argv[2], envp[3], pipex->outfile);
}
