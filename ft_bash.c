/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:33:02 by adrian            #+#    #+#             */
/*   Updated: 2020/10/12 16:40:09 by amunoz-p         ###   ########.fr       */
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
		if (f->arguments[0][0] == '/')
			j = execve(f->arguments[0], f->arguments, f->envv);
		else
		{
			aux = ft_strjoin3(f->path[i], f->arguments[0]);
			tmp = aux;
			j = execve(tmp, f->arguments, f->envv);
			free(aux);
		}
		i++;
	}
	aux = ft_strjoin3(f->pwd, f->arguments[0]);
	j = execve(aux, f->arguments, f->envv);
	f->erno = strerror(errno);
	free(aux);
	if (f->arguments[0][0] == '/')
		ft_404_kill(f);
	else
		ft_404(f);
}

void		ft_bash(char **path, t_shell *f)
{
	int		i;
	int		j;
	pid_t	id;

	i = 0;
	id = fork();
	signal(SIGINT, proc_signal_handler);
	signal(SIGQUIT, signal2);
	if (id == 0)
	{
		ft_bash_son(f, i);
	}
	else
	{
		waitpid(id, &f->statuss, 0);
		f->statuss = (f->statuss / 256);
	}
}
