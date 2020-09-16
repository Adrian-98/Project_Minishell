/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 12:05:03 by adrian            #+#    #+#             */
/*   Updated: 2020/09/16 17:52:28 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit1(t_shell *f)
{
}

void		ft_exit(t_shell *f)
{
	int i;

	i = 0;
	while (f->arguments[i])
		i++;
	if (i >= 3)
		ft_too_many(f);
	else
		exit(0);
}

void		ft_too_many(t_shell *f)
{
	printf("%s: too many arguments\n", f->arguments[0]);
}

void		ft_404(t_shell *f)
{
	f->line = ft_spaceserase(f->line);
	printf("zsh: command not found: %s\n", f->line);
}

void		ft_404_kill(t_shell *f)
{
	f->line = ft_spaceserase(f->line);
	printf("zsh: command not found: %s\n", f->line);
	//pipe("le tiene que decir al padre que no ha encontrado la funcion");
	exit(0);
}

