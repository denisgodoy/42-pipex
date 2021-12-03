/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:38:08 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/03 00:37:21 by degabrie         ###   ########.fr       */
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
		write(2, "Expected: ./pipex infile \"cmd1\" \"cmd2\" outfile\n", 48);
		ft_errno(EINVAL);
	}
	pipex->infile = argv[1];
	pipex->outfile = argv[argc - 1];
	if (ft_check_envp(pipex) < 0)
		exit(EXIT_FAILURE);
	pipex->cmd = (char **)malloc((argc - 2) * sizeof(char *));
	if (!pipex->cmd)
	{
		ft_free_arr(pipex->src.path);
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
			if (!pipex->src.path)
			{
				free(paths);
				ft_errno(ENOMEM);
			}
			free(paths);
			i = -1;
			while (pipex->src.path[++i])
				pipex->src.path[i] = ft_strjoin_free(pipex->src.path[i], "/");
			return (0);
		}
	}
	return (-1);
}
