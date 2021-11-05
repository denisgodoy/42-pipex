/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:32:49 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/05 00:36:02 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		fd1;
	int		fd2;

	ft_check_args(&pipex, argc, argv, envp);
	if ((access(pipex.infile, R_OK) < 0) || (access(pipex.outfile, W_OK) < 0))
	{
		ft_free_cmd(&pipex);
		ft_free_path(&pipex);
		perror("Error");
		exit(EXIT_FAILURE);
	}
	fd1 = open(pipex.infile, O_RDONLY);
	fd2 = open(pipex.outfile, O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (fd1 < 0 || fd2 < 0)
	{
		ft_free_cmd(&pipex);
		ft_free_path(&pipex);
		return (-1);
	}
	ft_cmd_format(&pipex);
	ft_pipex(&pipex, fd1, fd2);
	ft_free_cmd(&pipex);
	ft_free_path(&pipex);
	return (0);
}
