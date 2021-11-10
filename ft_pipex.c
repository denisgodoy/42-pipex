/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:05:39 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/10 01:54:12 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

static char	*ft_exec_cmd(t_pipex *pipex, int arg, char **envp);

void	ft_pipex(t_pipex *pipex, char **envp, int fd1, int fd2)
{
	int		piped[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(piped) < 0)
		exit(EXIT_FAILURE);
	pid1 = fork();
	if (pid1 < 0)
		exit(EXIT_FAILURE);
	if (!pid1)
	{
		dup2(fd1, STDIN_FILENO);
		dup2(piped[1], STDOUT_FILENO);
		close(piped[0]);
		close(fd1);
		ft_exec_cmd(pipex, 0, envp);
	}
	pid2 = fork();
	if (pid2 < 0)
		exit(EXIT_FAILURE);
	if (!pid2)
	{
		dup2(fd2, STDOUT_FILENO);
		dup2(piped[0], STDIN_FILENO);
		close(piped[1]);
		close(fd2);
		ft_exec_cmd(pipex, 1, envp);
	}
	close(piped[0]);
	close(piped[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

static char	*ft_exec_cmd(t_pipex *pipex, int arg, char **envp)
{
	int		i;
	char	*path;
	char	**cmd;

	cmd = ft_split(pipex->cmd[1], ' ');
	i = -1;
	while (pipex->utils.path[i])
	{
		path = ft_strjoin(pipex->utils.path[++i], pipex->utils.cmd[arg]);
		if (!access(path, X_OK))
			execve(path, cmd, envp);
		free(path);
	}
	unlink(pipex->outfile);
	perror("Error");
	exit(EXIT_FAILURE);
}
