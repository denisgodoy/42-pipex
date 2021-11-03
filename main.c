/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:32:49 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/03 15:43:18 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

int	main(int argc, char **argv)
{
	t_pipex	pipex;
	int		fd1;
	int		fd2;

	ft_check_args(&pipex, argc, argv);
	fd1 = open(pipex.infile, O_RDONLY);
	fd2 = open(pipex.outfile, O_CREAT);
	printf("%s\n%s\n", pipex.infile, pipex.outfile);
	return (0);
}
