/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:32:49 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/10 16:50:58 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	pipex.src.envp = envp;
	ft_check_args(&pipex, argc, argv);
	pipex.fd1 = open(pipex.infile, O_RDONLY);
	pipex.fd2 = open(pipex.outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex.fd1 < 0 || pipex.fd2 < 0)
	{
		ft_free_cmd(&pipex);
		ft_free_path(&pipex);
		unlink(pipex.outfile);
		perror(strerror(EBADF));
		return (-1);
	}
	ft_cmd_format(&pipex);
	ft_pipex(&pipex);
	ft_free_cmd(&pipex);
	ft_free_path(&pipex);
	ft_free_utils(&pipex);
	return (0);
}
