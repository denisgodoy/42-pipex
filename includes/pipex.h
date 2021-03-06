/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:28:11 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/13 19:16:49 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>

# define ENOMEM			12
# define EINVAL			22
# define ECHILD			10
# define EXIT_INVCMD	127

enum e_process
{
	cmd1,
	cmd2
};

typedef struct s_src
{
	char	**cmd;
	char	**path;
	char	**envp;
	int		cmdlen;
}	t_src;

typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	char	**cmd;
	int		fd1;
	int		fd2;
	t_src	src;
}	t_pipex;

void	ft_check_args(t_pipex *pipex, int argc, char **argv);
char	*ft_check_shell(t_pipex *pipex, char *msg, char *err);
void	ft_errno(int errno);
void	ft_error_handler(t_pipex *pipex, char *msg, char *err);
void	ft_free_arr(char **arr);
int		ft_pipex(t_pipex *pipex);
int		ft_pre_split(t_pipex *pipex, char *cmd, int arg);
void	ft_update_char(t_pipex *pipex);

int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_free(char *s1, char const *s2);
size_t	ft_strlcpy(char	*dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
