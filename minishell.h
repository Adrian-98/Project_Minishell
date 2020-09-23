/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 19:20:28 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/09/23 19:39:12 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef  MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <signal.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include <errno.h>

int			ft_export(t_shell *f);
void		display_msg(t_shell *f);
void		ft_pwd(t_shell *f);
void		ft_cases(t_shell *f);
void		ft_404(t_shell *f);
void		ft_exit(t_shell *f);
void		ft_404_kill(t_shell *f);
void		ft_too_many(t_shell *f);
void		ft_exit1(t_shell *f);
void		ft_echo(t_shell *f);
int			ft_quotes(t_shell *f);
void		ft_quote2(t_shell *f);
int			ft_quotes1(t_shell *f);
void		ft_bash(char **path, t_shell *f);
int			chdir(const char *path);
void		ft_cd(t_shell *f);
void		ft_extra2(char *temp, t_shell *f);
void		ft_extra(char *temp, t_shell *f);
void		display_msg1(t_shell *f);
char    	*ft_var(char *str, t_shell *f);
void    	ft_get_path(t_shell *f);
void		ft_clear(t_shell *f);

#endif
