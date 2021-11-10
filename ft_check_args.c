/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:42:45 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/10 16:56:11 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

static int	ft_check_envp(t_pipex *pipex);

void	ft_check_args(t_pipex *pipex, int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 5)
	{
		perror(strerror(EINVAL));
		exit(EXIT_FAILURE);
	}
	pipex->infile = argv[1];
	pipex->outfile = argv[argc - 1];
	if (ft_check_envp(pipex) < 0)
		exit(EXIT_FAILURE);
	pipex->cmd = (char **)malloc((argc - 2) * sizeof(char *));
	if (!pipex->cmd)
	{
		ft_free_path(pipex);
		perror(strerror(ENOMEM));
		exit(EXIT_FAILURE);
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
