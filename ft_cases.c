/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:33:02 by adrian            #+#    #+#             */
/*   Updated: 2020/09/24 17:25:18 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cases(t_shell *f)
{
	if (f->arguments[0] == NULL)
		ft_exit1(f);
	else if (ft_strncmp("exit", f->arguments[0],
			ft_strlen("exit")) == 0)
		ft_exit(f);
	else if (ft_strncmp("pwd", f->arguments[0],
			ft_strlen("pwd")) == 0)
		ft_pwd(f);
	else if (ft_strncmp("echo", f->arguments[0],
			ft_strlen("echo")) == 0)
		ft_echo(f);
	else if (ft_strncmp("cd", f->arguments[0],
			ft_strlen("cd")) == 0)
		ft_cd(f);
	else if (ft_strncmp("export", f->arguments[0],
			ft_strlen("export")) == 0)
		ft_export_while(f);
	// else if (ft_strncmp("unset", f->arguments[0],
	// 		ft_strlen("unset")) == 0)
	// 	ft_unset(f);
	else
		ft_bash(f->path, f);
	f->line = 0;
	f->arguments = 0;
}
