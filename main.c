/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:32:49 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/03 13:37:54 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

int	main(int argc, char **argv)
{
	t_pipex	pipex;
	int		i;
	char	*cmd_str;

	pipex.infile = argv[1];
	pipex.outfile = argv[argc - 1];
	printf("%s\n%s\n", pipex.infile, pipex.outfile);
	i = 2;
	cmd_str = ft_strdup("");
	while (i < argc - 1)
	{
		cmd_str = ft_strjoin_free(cmd_str, argv[i]);
		printf("%s\n", cmd_str);
		i++;
	}
	free(cmd_str);
	return (0);
}
