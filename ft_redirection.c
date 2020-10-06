/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 17:01:34 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/10/06 20:39:14 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_redi(char *str, t_shell *f)
{
	int i;
	int j;
	char **temp;
	
	j = 0;
	i = 0;
	temp = ft_split2(str, ' ');
	while (temp[i])
	{
		if ((ft_strcmp(">", temp[i]) == 0))
			f->z = 1;
		else if ((ft_strcmp(">>", temp[i]) == 0))
			f->x = 1;
		else if ((ft_strcmp("<", temp[i]) == 0))
			f->c = 1;
		i++;
	}
	free(temp);
	return (0);
}

void		ft_body_redi(t_shell *f)
{
	if (f->z == 1)
		f->redi = ft_split2(f->pipes[f->i], '>');
	else if (f->x == 1)
		f->redi = ft_split_cmd(f->pipes[f->i], ">>", f);
	else if (f->c == 1)
		f->redi = ft_split2(f->pipes[f->i], '<');
	if (f->z == 1)
	{
		f->fd2 = open(f->redi[1], O_CREAT | O_WRONLY);
		if (f->fd2  < 0)
		{
			ft_printf("%s\n", strerror(errno));
			exit (1);
		}
		f->ret = dup2(f->fd2, 1);
		ft_body_redi2(f);
		close(f->fd2);
	}
	if (f->x == 1)
	{
		f->fd2 = open(f->redi[1], O_APPEND);
		if (f->fd2  < 0)
		{
			ft_printf("%s\n", strerror(errno));
			exit (1);
		}
		f->ret = dup2(f->fd2, 1);
		ft_body_redi2(f);
		close(f->fd2);
	}
}

void		ft_body_redi2(t_shell *f)
{
	f->arguments = ft_split(f->redi[0], ' ', f);
	ft_$(f);
	ft_cases(f);
}