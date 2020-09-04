/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:33:02 by adrian            #+#    #+#             */
/*   Updated: 2020/09/01 19:58:49 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cases(t_shell *f)
{
	if (f->arguments[0] == NULL)
		ft_exit1(f);
	else if (ft_strncmp("exit", f->arguments[0],
			ft_strlen(f->arguments[0])) == 0)
		ft_exit(f);
	else if (ft_strncmp("pwd", f->arguments[0],
			ft_strlen(f->arguments[0])) == 0)
		ft_pwd(f);
	else if (ft_strncmp("echo", f->arguments[0],
			ft_strlen(f->arguments[0])) == 0)
		{
			//printf("asd\n");
			ft_echo(f);
		}
	else
		ft_404(f);
	f->line = 0;
	f->arguments = 0;
	//ifree(f->line);
}
