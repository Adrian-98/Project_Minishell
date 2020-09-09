/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 19:20:28 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/09/09 17:56:23 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

void		display_msg(t_shell *f);
void		ft_pwd(t_shell *f);
void		ft_cases(t_shell *f);
void		ft_404(t_shell *f);
void		ft_exit(t_shell *f);
void		ft_too_many(t_shell *f);
void		ft_exit1(t_shell *f);
void		ft_echo(t_shell *f);

#endif