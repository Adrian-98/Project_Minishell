/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:33:02 by adrian            #+#    #+#             */
/*   Updated: 2020/10/12 16:41:20 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cases(t_shell *f)
{
	if (f->arguments[0] == NULL)
		ft_exit1(f);
	else if (ft_strcmp("exit", f->arguments[0]) == 0)
		ft_exit(f);
	else if (ft_strcmp("pwd", f->arguments[0]) == 0)
		ft_pwd(f);
	else if (ft_strcmp("echo", f->arguments[0]) == 0)
		ft_echo(f);
	else if (ft_strcmp("cd", f->arguments[0]) == 0)
		ft_cd(f);
	else if (ft_strcmp("export", f->arguments[0]) == 0)
		ft_export_while(f);
	else if (ft_strcmp("unset", f->arguments[0]) == 0)
		ft_unset_while(f);
	else if (ft_strcmp("env", f->arguments[0]) == 0)
		ft_env(f);
	else
		ft_bash(f->path, f);
	f->line = 0;
	ft_free_matrix(f->arguments);
	f->arguments = 0;
}
