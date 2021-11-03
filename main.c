/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:32:49 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/03 19:21:39 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

int	main(int argc, char **argv)
{
	t_pipex	pipex;
	int		fd1;
	int		fd2;

	ft_check_args(&pipex, argc, argv);
	fd1 = open(pipex.infile, O_RDONLY);
	if (fd1 < 0)
	{
		ft_free_arr(&pipex);
		return (0);
	}
	close(fd1);
	fd2 = open(pipex.outfile, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	write(fd2, pipex.cmd[1], ft_strlen(pipex.cmd[1]));
	close(fd2);
	ft_free_arr(&pipex);
	return (0);
}
