/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-a <glopez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:33:02 by adrian            #+#    #+#             */
/*   Updated: 2020/09/15 20:00:32 by glopez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_bash(t_shell *f)
{
	char *aux;
	int	i;
	int	j;

	i = 0;
	while (f->path[i])
	{
		aux = ft_strjoin(f->path[i], *f->arguments);
		//printf("%s\n", aux);
		j = execve(aux, f->arguments, f->envv);
		free(aux);
		i++;
	}
	printf("adios\n");
}