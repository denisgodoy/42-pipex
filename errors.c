/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:18:48 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/17 22:11:20 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

void	ft_errno(int errno)
{
	char	*err_msg;

	err_msg = strerror(errno);
	write(2, err_msg, ft_strlen(err_msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	ft_error_handler(t_pipex *pipex, char *msg, char *err)
{
	char	*shell;

	shell = ft_check_shell(pipex, msg, err);
	write(2, shell, ft_strlen(shell));
	free(shell);
	return ;
}
