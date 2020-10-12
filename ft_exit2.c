/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 16:46:23 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/10/12 20:01:59 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_404(t_shell *f)
{
	dup2(f->save[0], STDIN_FILENO);
	dup2(f->save[1], STDOUT_FILENO);
	f->line = ft_spaceserase(f->line);
	ft_printf("zsh: command not found: %s\n", f->arg[0]);
	exit(127);
}

void		ft_404_kill(t_shell *f)
{
	dup2(f->save[0], STDIN_FILENO);
	dup2(f->save[1], STDOUT_FILENO);
	ft_printf("zsh: %s: %s\n", f->erno, f->arg[0]);
	exit(127);
}
