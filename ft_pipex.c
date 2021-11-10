/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:05:39 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/09 23:08:06 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

static int	ft_valid_path(t_pipex *pipex, int arg);

void	ft_pipex(t_pipex *pipex, char **envp)
{
	int		fd[2];
	int		pid1;
	int		i;
	char	**cmd;

	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);
	pid1 = fork();
	if (pid1 < 0)
		exit(EXIT_FAILURE);
	i = -1;
	if (pid1 == 0)
	{
		cmd = ft_split(pipex->cmd[0], ' ');
		execve(pipex->utils.path[ft_valid_path(pipex, 0)], cmd, envp);
	}
	waitpid(pid1, NULL, 0);
	return ;
}

static int	ft_valid_path(t_pipex *pipex, int arg)
{
	int		i;
	char	*path;

	i = -1;
	while (pipex->utils.path[i])
	{
		path = ft_strjoin(pipex->utils.path[++i], pipex->utils.cmd[arg]);
		if (access(path, X_OK) == 0)
		{
			free(path);
			return (i);
		}
		free(path);
	}
	unlink(pipex->outfile);
	perror("Error");
	exit(EXIT_FAILURE);
}
