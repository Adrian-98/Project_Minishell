/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-a <glopez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:33:02 by adrian            #+#    #+#             */
/*   Updated: 2020/09/15 20:22:35 by glopez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_bash(t_shell *f)
{
	char	*aux;
	char	*tmp;	
	int		i;
	int		j;
	pid_t	id;

	i = 0;
	id = fork();
	if (id == 0)
		while (f->path[i])
		{
			aux = ft_strjoin(f->path[i], *f->arguments);
			//printf("%s\n", aux);
			tmp = aux;
			free(aux);
			j = execve(tmp, f->arguments, f->envv);
			//free(aux);
			//printf("%d\n", j);
			i++;
		}
		if (j == -1)
			ft_404_kill(f);
	else
		wait(0);
}