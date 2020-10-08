/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-a <glopez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:33:02 by adrian            #+#    #+#             */
/*   Updated: 2020/10/08 20:04:22 by glopez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_bash(char **path, t_shell *f)
{
	char	*aux;
	char	*tmp;
	int		i;
	int		j;
	pid_t	id;

	//printf("valor de :%s,\n%s\n", f->arguments[0], f->arguments[1]);
	i = 0;
	id = fork();
	signal(SIGINT, proc_signal_handler);
	signal(SIGQUIT, signal2);
	if (id == 0)
	{
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
	else
		waitpid(id, &f->statuss, 0);
		f->statuss = f->statuss / 256;
		printf("%i\n", f->statuss);
}
