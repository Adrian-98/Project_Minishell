/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-a <glopez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:33:02 by adrian            #+#    #+#             */
/*   Updated: 2020/10/13 18:00:52 by glopez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_bash_son(t_shell *f, int i)
{
	char	*aux;
	char	*tmp;
	int		j;

	while (f->path[i])
	{
		if (f->arg[0][0] == '/')
			j = execve(f->arg[0], f->arg, f->envv);
		else
		{
			aux = ft_strjoin3(f->path[i], f->arg[0]);
			tmp = aux;
			j = execve(tmp, f->arg, f->envv);
			free(aux);
		}
		i++;
	}
	aux = ft_strjoin3(f->pwd, f->arg[0]);
	j = execve(aux, f->arg, f->envv);
	f->erno = strerror(errno);
	free(aux);
	if (f->arg[0][0] == '/')
		ft_404_kill(f);
	else
		ft_404(f);
}

void			ft_bash(char **path, t_shell *f)
{
	int		i;
	int		j;
	pid_t	pidt;

	i = 0;
	pidt = fork();
	signal(SIGINT, proc_signal_handler);
	signal(SIGQUIT, signal2);
	if (pidt == 0)
	{
		ft_bash_son(f, i);
	}
	else
	{
		waitpid(pidt, &f->statuss, 0);
		f->statuss = (f->statuss / 256);
	}
}
