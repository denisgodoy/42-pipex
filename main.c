/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:32:49 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/17 10:29:46 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		status;
	char	*shell;

	pipex.src.envp = envp;
	ft_check_args(&pipex, argc, argv);
	pipex.fd1 = open(pipex.infile, O_RDONLY);
	pipex.fd2 = open(pipex.outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex.fd2 < 0)
	{
		shell = ft_check_shell(&pipex, ": permission denied\n", pipex.outfile);
		write(2, shell, ft_strlen(shell));
		ft_free_cmd(&pipex);
		ft_free_path(&pipex);
		free(shell);
		exit(EXIT_FAILURE);
	}
	status = ft_pipex(&pipex);
	ft_free_cmd(&pipex);
	ft_free_path(&pipex);
	exit(status);
}
