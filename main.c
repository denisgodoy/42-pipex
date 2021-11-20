/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:32:49 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/19 21:27:33 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

static void	ft_check_args(t_pipex *pipex, int argc, char **argv);
static int	ft_check_envp(t_pipex *pipex);

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

static void	ft_check_args(t_pipex *pipex, int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 5)
		ft_errno(EINVAL);
	pipex->infile = argv[1];
	pipex->outfile = argv[argc - 1];
	if (ft_check_envp(pipex) < 0)
		exit(EXIT_FAILURE);
	pipex->cmd = (char **)malloc((argc - 2) * sizeof(char *));
	if (!pipex->cmd)
	{
		ft_free_path(pipex);
		ft_errno(ENOMEM);
	}
	i = -1;
	j = 2;
	while (j < argc - 1)
		pipex->cmd[++i] = ft_strdup(argv[j++]);
	pipex->cmd[i + 1] = NULL;
	pipex->src.cmdlen = i;
	return ;
}

static int	ft_check_envp(t_pipex *pipex)
{
	int		i;
	size_t	envlen;
	char	*paths;

	i = -1;
	while (pipex->src.envp[++i])
	{
		envlen = ft_strlen(pipex->src.envp[i]);
		if (!ft_memcmp(pipex->src.envp[i], "PATH", 4))
		{
			paths = ft_substr(pipex->src.envp[i], 5, envlen);
			pipex->src.path = ft_split(paths, ':');
			free(paths);
			i = -1;
			while (pipex->src.path[++i])
				pipex->src.path[i] = ft_strjoin_free(pipex->src.path[i], "/");
			return (0);
		}
	}
	return (-1);
}
