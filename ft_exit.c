/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 12:05:03 by adrian            #+#    #+#             */
/*   Updated: 2020/10/14 17:35:17 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_free_matrix(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void		ft_exit1(t_shell *f)
{
	dup2(f->save[0], STDIN_FILENO);
	dup2(f->save[1], STDOUT_FILENO);
}

void		ft_exit(t_shell *f)
{
	int i;
	int j;

	j = 0;
	i = 0;
	dup2(f->save[0], STDIN_FILENO);
	dup2(f->save[1], STDOUT_FILENO);
	while (f->arg[i])
		i++;
	if (i >= 3)
		ft_too_many(f);
	else if (f->arg[1])
	{
		j = ft_atoi(f->arg[1]);
		exit(j);
	}
	else
	{
		system("leaks minishell");
		exit(0);
	}
}

void		ft_too_many(t_shell *f)
{
	dup2(f->save[0], STDIN_FILENO);
	dup2(f->save[1], STDOUT_FILENO);
	ft_printf("%s: too many arguments\n", f->arg[0]);
}
