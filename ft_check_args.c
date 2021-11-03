/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:42:45 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/03 19:18:01 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

void	ft_check_args(t_pipex *pipex, int argc, char **argv)
{
	int		i;
	int		j;

	if (argc < 5)
	{
		write(1, "Invalid number of arguments.\n", 29);
		exit(EXIT_FAILURE);
	}
	pipex->infile = argv[1];
	pipex->outfile = argv[argc - 1];
	pipex->cmd = (char **)malloc((argc - 2) * sizeof(char *));
	if (!pipex->cmd)
		exit(EXIT_FAILURE);
	i = 0;
	j = 2;
	while (j < argc - 1)
		pipex->cmd[i++] = ft_strdup(argv[j++]);
	pipex->cmd[i] = NULL;
	return ;
}
