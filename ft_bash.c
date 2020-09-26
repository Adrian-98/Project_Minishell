/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:33:02 by adrian            #+#    #+#             */
/*   Updated: 2020/09/26 14:51:06 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static 	void handle_sigint(int sig)
// {
// 	ft_printf("entro aqui\n");
// 	kill(getpid(), 3);
// }


void	ft_bash(char **path, t_shell *f)
{
	char	*aux;
	char	*tmp;
	int		i;
	int		j;
	pid_t	id;

	// signal(SIGINT, handle_sigint);
	i = 0;
	id = fork();
	signal(SIGINT, proc_signal_handler);
	if (id == 0)
	{
		while (f->path[i])
		{
			aux = ft_strjoin3(f->path[i], *f->arguments);
			tmp = aux;
			j = execve(tmp, f->arguments, f->envv);
			free(aux);
			i++;
		}
		aux = ft_strjoin3(f->pwd, *f->arguments);
		j = execve(aux, f->arguments, f->envv);
		f->erno = strerror(errno);
		free(aux);
		if (**f->arguments == '/')
			ft_404_kill(f);
		else
			ft_404(f);
	}
	else
		wait(0);
}
