/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:28:11 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/04 23:58:25 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	char	**path;
	char	**cmd;
	char	**cmd_path;
	int		cmd_len;
}	t_pipex;

void	ft_check_args(t_pipex *pipex, int argc, char **argv, char **envp);
void	ft_cmd_format(t_pipex *pipex);
void	ft_free_cmd(t_pipex *pipex);
void	ft_free_path(t_pipex *pipex);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_pipex(t_pipex *pipex, int fd1, int fd2);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char	*dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin_free(char *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif