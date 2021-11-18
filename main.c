/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:32:49 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/17 23:26:57 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		status;

	pipex.src.envp = envp;
	ft_check_args(&pipex, argc, argv);
	pipex.fd1 = open(pipex.infile, O_RDONLY);
	if (!access(pipex.infile, F_OK) && pipex.fd1 < 0)
		ft_error_handler(&pipex, ": permission denied\n", pipex.infile);
	pipex.fd2 = open(pipex.outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex.fd2 < 0)
	{
		ft_error_handler(&pipex, ": permission denied\n", pipex.outfile);
		ft_free_cmd(&pipex);
		ft_free_path(&pipex);
		exit(EXIT_FAILURE);
	}
	status = ft_pipex(&pipex);
	ft_free_cmd(&pipex);
	ft_free_path(&pipex);
	exit(status);
}
