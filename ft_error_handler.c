/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:18:48 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/17 18:48:00 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

void	ft_error_handler(int errno)
{
	char	*err_msg;

	err_msg = strerror(errno);
	write(2, err_msg, ft_strlen(err_msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
