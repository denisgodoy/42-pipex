/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:05:39 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/10 02:52:52 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

static void	ft_exec_cmd(t_pipex *pipex, int arg);
static void	ft_pipe_process(t_pipex *pipex, int process, int *piped);

void	ft_pipex(t_pipex *pipex)
{
	int		piped[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;
	
	if (pipe(piped) < 0)
		exit(EXIT_FAILURE);
	pid1 = fork();
	if (pid1 < 0)
		exit(EXIT_FAILURE);
	if (!pid1)
		ft_pipe_process(pipex, child, piped);
	pid2 = fork();
	if (pid2 < 0)
		exit(EXIT_FAILURE);
	if (!pid2)
		ft_pipe_process(pipex, parent, piped);
	close(piped[0]);
	close(piped[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	exit(status);
}

static void	ft_pipe_process(t_pipex *pipex, int process, int *piped)
{
	if (process == child)
	{
		dup2(pipex->fd1, STDIN_FILENO);
		dup2(piped[1], STDOUT_FILENO);
		close(piped[0]);
		close(pipex->fd1);
		ft_exec_cmd(pipex, cmd1);
	}
	else if (process == parent)
	{
		dup2(piped[0], STDIN_FILENO);
		dup2(pipex->fd2, STDOUT_FILENO);
		close(piped[1]);
		close(pipex->fd2);
		ft_exec_cmd(pipex, cmd2);
	}
}

static void	ft_exec_cmd(t_pipex *pipex, int arg)
{
	int		i;
	char	*path;
	char	**cmd;

	cmd = ft_split(pipex->cmd[arg], ' ');
	i = -1;
	while (pipex->src.path[i])
	{
		path = ft_strjoin(pipex->src.path[++i], pipex->src.cmd[arg]);
		if (!access(path, X_OK))
			execve(path, cmd, pipex->src.envp);
		free(path);
	}
	unlink(pipex->outfile);
	perror("Error");
	exit(EXIT_FAILURE);
}
