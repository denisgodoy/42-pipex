/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:42:45 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/10 00:58:52 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

static int	ft_check_envp(t_pipex *pipex, char **envp);

void	ft_check_args(t_pipex *pipex, int argc, char **argv, char **envp)
{
	int	i;
	int	j;

	if (argc != 5)
	{
		write(1, "Invalid number of arguments.\n", 29);
		exit(EXIT_FAILURE);
	}
	pipex->infile = argv[1];
	pipex->outfile = argv[argc - 1];
	if (ft_check_envp(pipex, envp) < 0)
		exit(EXIT_FAILURE);
	pipex->cmd = (char **)malloc((argc - 2) * sizeof(char *));
	if (!pipex->cmd)
	{
		ft_free_path(pipex);
		exit(EXIT_FAILURE);
	}
	i = -1;
	j = 2;
	while (j < argc - 1)
		pipex->cmd[++i] = ft_strdup(argv[j++]);
	pipex->cmd[i + 1] = NULL;
	pipex->utils.cmd_len = i;
	return ;
}

static int	ft_check_envp(t_pipex *pipex, char **envp)
{
	int		i;
	int		diff;
	char	*paths;

	i = -1;
	while (envp[++i])
	{
		diff = ft_memcmp(envp[i], "PATH", 4);
		if (!diff)
			break ;
	}
	if (diff)
		return (-1);
	paths = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	pipex->utils.path = ft_split(paths, ':');
	i = -1;
	while (pipex->utils.path[++i])
		pipex->utils.path[i] = ft_strjoin_free(pipex->utils.path[i], "/");
	free(paths);
	return (0);
}
