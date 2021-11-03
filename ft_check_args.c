/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:42:45 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/03 15:48:17 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

void	ft_check_args(t_pipex *pipex, int argc, char **argv)
{
	int		i;
	char	*cmd_str;

	if (argc < 5)
	{
		write(1, "Invalid number of arguments.\n", 29);
		exit(EXIT_FAILURE);
	}
	pipex->infile = argv[1];
	pipex->outfile = argv[argc - 1];
	cmd_str = ft_strdup("");
	i = 2;
	while (i < argc - 1)
	{
		cmd_str = ft_strjoin_free(cmd_str, argv[i]);
		i++;
	}
	printf("%s\n", cmd_str);
	free(cmd_str);
	return ;
}
