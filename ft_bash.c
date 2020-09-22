/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:33:02 by adrian            #+#    #+#             */
/*   Updated: 2020/09/22 16:43:54 by amunoz-p         ###   ########.fr       */
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

	i = 0;
	id = fork();
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
