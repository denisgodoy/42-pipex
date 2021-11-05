/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:05:39 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/04 20:51:48 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

void	ft_pipex(t_pipex *pipex, int fd1, int fd2)
{
	printf("fd1: %d\nfd2: %d\noutfile: %s\n", fd1, fd2, pipex->outfile);
}
