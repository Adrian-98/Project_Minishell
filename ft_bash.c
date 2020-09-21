/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:33:02 by adrian            #+#    #+#             */
/*   Updated: 2020/09/21 20:17:03 by amunoz-p         ###   ########.fr       */
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
			printf("valor de aux  [%s]\n", aux);
			printf("valor de function  [%s]\n",	*f->arguments);
			j = execve(tmp, f->arguments, f->envv);
			free(aux);
			i++;
		}
		aux = ft_strjoin3(f->pwd, *f->arguments);
		j = execve(aux, f->arguments, f->envv);
		printf("valor de j [%d]\n", j);

		free(aux);
		ft_404_kill(f);
	}
	else
		wait(0);
}
