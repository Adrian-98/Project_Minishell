/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-a <glopez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:33:02 by adrian            #+#    #+#             */
/*   Updated: 2020/10/13 18:03:02 by glopez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cases(t_shell *f)
{
	f->statuss = 0;
	if (f->arg[0] == NULL)
		ft_exit1(f);
	else if (ft_strcmp("exit", f->arg[0]) == 0)
		ft_exit(f);
	else if (ft_strcmp("pwd", f->arg[0]) == 0)
		ft_pwd(f);
	else if (ft_strcmp("echo", f->arg[0]) == 0)
		ft_echo(f);
	else if (ft_strcmp("cd", f->arg[0]) == 0)
		ft_cd(f);
	else if (ft_strcmp("export", f->arg[0]) == 0)
		ft_export_while(f);
	else if (ft_strcmp("unset", f->arg[0]) == 0)
		ft_unset_while(f);
	else if (ft_strcmp("env", f->arg[0]) == 0)
		ft_env(f);
	else
		ft_bash(f->path, f);
	f->line = 0;
	ft_free_matrix(f->arg);
	f->arg = 0;
}
