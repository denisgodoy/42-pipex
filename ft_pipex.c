/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:05:39 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/11 21:35:33 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

static void	ft_exec_cmd(t_pipex *pipex, int arg);
static void	ft_pipe_process(t_pipex *pipex, int process, int *piped);
static char	*ft_check_shell(t_pipex *pipex);

void	ft_pipex(t_pipex *pipex)
{
	int		piped[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(piped) < 0)
		exit(EXIT_FAILURE);
	pid1 = fork();
	if (pid1 < 0)
		ft_error_handler(ECHILD);
	else if (!pid1)
		ft_pipe_process(pipex, child, piped);
	pid2 = fork();
	if (pid2 < 0)
		ft_error_handler(ECHILD);
	else if (!pid2)
		ft_pipe_process(pipex, parent, piped);
	close(piped[0]);
	close(piped[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
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
	char	*shell;

	pipex->src.cmd = ft_split(pipex->cmd[arg], ' ');
	i = -1;
	while (pipex->src.path[++i])
	{
		path = ft_strjoin(pipex->src.path[i], *pipex->src.cmd);
		if (!access(path, X_OK))
			execve(path, pipex->src.cmd, pipex->src.envp);
		free(path);
	}
	shell = ft_check_shell(pipex);
	write(2, shell, ft_strlen(shell));
	write(2, ": command not found: ", 21);
	write(2, *pipex->src.cmd, ft_strlen(*pipex->src.cmd));
	write(2, "\n", 1);
	ft_free_cmd(pipex);
	ft_free_path(pipex);zsh
	
	ft_free_src(pipex);
	free(shell);
	exit(EXIT_FAILURE);
}

static char	*ft_check_shell(t_pipex *pipex)
{
	int		i;
	size_t	envlen;
	char	*shell;

	i = -1;
	shell = NULL;
	while (pipex->src.envp[++i])
	{
		envlen = ft_strlen(pipex->src.envp[i]);
		if (!ft_memcmp(pipex->src.envp[i], "SHELL", 5))
			shell = ft_strdup(ft_strrchr(pipex->src.envp[i], '/') + 1);
	}
	return (shell);
}
