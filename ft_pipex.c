/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:05:39 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/04 20:35:28 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

static void	ft_pipe_child1(t_pipex *pipex, int *piped);
static void	ft_pipe_child2(t_pipex *pipex, int *piped);
static void	ft_exec_cmd(t_pipex *pipex, int arg);
static void	ft_exit_free(t_pipex *pipex, int arg);

int	ft_pipex(t_pipex *pipex)
{
	int		piped[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	pipe(piped);
	pid1 = fork();
	if (pid1 < 0)
		ft_errno(ECHILD);
	else if (!pid1)
		ft_pipe_child1(pipex, piped);
	pid2 = fork();
	if (pid2 < 0)
		ft_errno(ECHILD);
	else if (!pid2)
		ft_pipe_child2(pipex, piped);
	close(piped[0]);
	close(piped[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	return (WEXITSTATUS(status));
}

static void	ft_pipe_child1(t_pipex *pipex, int *piped)
{
	if (dup2(pipex->fd1, STDIN_FILENO) < 0)
	{
		if (access(pipex->infile, F_OK) < 0)
			ft_error_handler(pipex, ": no such file or directory\n",
				pipex->infile);
		close(STDIN_FILENO);
		ft_free_arr(pipex->cmd);
		ft_free_arr(pipex->src.path);
		exit(EXIT_SUCCESS);
	}
	dup2(piped[1], STDOUT_FILENO);
	close(piped[0]);
	close(pipex->fd1);
	ft_exec_cmd(pipex, cmd1);
}

static void	ft_pipe_child2(t_pipex *pipex, int *piped)
{
	dup2(piped[0], STDIN_FILENO);
	dup2(pipex->fd2, STDOUT_FILENO);
	close(piped[1]);
	close(pipex->fd2);
	ft_exec_cmd(pipex, cmd2);
}

static void	ft_exec_cmd(t_pipex *pipex, int arg)
{
	int		i;
	char	*path;

	i = ft_pre_split(pipex, pipex->cmd[arg], arg);
	pipex->src.cmd = ft_split(pipex->cmd[arg], ' ');
	if (i)
		ft_update_char(pipex);
	if (*pipex->src.cmd != NULL && ft_strrchr(*pipex->src.cmd, '/'))
		if (!access(*pipex->src.cmd, X_OK))
			execve(*pipex->src.cmd, pipex->src.cmd, pipex->src.envp);
	if (*pipex->src.cmd != NULL)
	{
		i = -1;
		while (pipex->src.path[++i])
		{
			path = ft_strjoin(pipex->src.path[i], *pipex->src.cmd);
			if (!access(path, X_OK))
				execve(path, pipex->src.cmd, pipex->src.envp);
			free(path);
		}
		ft_error_handler(pipex, ": command not found\n", *pipex->src.cmd);
		ft_exit_free(pipex, 1);
	}
	ft_exit_free(pipex, 0);
}

static void	ft_exit_free(t_pipex *pipex, int arg)
{
	ft_free_arr(pipex->cmd);
	ft_free_arr(pipex->src.path);
	if (!arg)
	{
		free(pipex->src.cmd);
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_free_arr(pipex->src.cmd);
		exit(EXIT_INVCMD);
	}
}
