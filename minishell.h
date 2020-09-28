/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 19:20:28 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/09/28 19:40:23 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef  MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "printf/printf_bonus.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <signal.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include <errno.h>

int			ft_export(t_shell *f, char *str, char **tmp);
void		display_msg(void);
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
void    	ft_get_user(t_shell *f);
void		ft_bash(char **path, t_shell *f);
int			chdir(const char *path);
void		ft_cd(t_shell *f);
void		ft_extra2(char *temp, t_shell *f);
void		ft_extra(char *temp, t_shell *f);
void		display_msg1(t_shell *f);
char    	*ft_var(char *str, t_shell *f);
void    	ft_get_path(t_shell *f);
void		ft_clear(t_shell *f);
int			ft_already(t_shell *f, char *aux);
int			ft_export_while(t_shell *f);
int			ft_unset(t_shell *f, char *str, char **tmp);
int			ft_unset_while(t_shell *f);
void		proc_signal_handler(int signo);
void		signal_handler(int signo);
void		signal1(int signo);
void		signal2(int signo);
#endif
