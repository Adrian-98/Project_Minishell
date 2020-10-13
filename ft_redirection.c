/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-a <glopez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 17:01:34 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/10/13 19:30:20 by glopez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_redi(char *str, t_shell *f)
{
	int		i;
	int		j;
	char	**temp;

	f->c = 0;
	f->z = 0;
	f->x = 0;
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
	ft_free_matrix(temp);
	return (0);
}

void		ft_body_redi(t_shell *f)
{
	char *tmp;

	if (f->z == 1)
		f->redi = ft_split2(f->pipes[f->i], '>');
	else if (f->x == 1)
		f->redi = ft_split_cmd(f->pipes[f->i], ">>", f);
	else if (f->c == 1)
		f->redi = ft_split2(f->pipes[f->i], '<');
	if (f->z == 1)
		ft_redi_z(f, tmp);
	else if (f->x == 1)
		ft_redi_x(f, tmp);
	else if (f->c == 1)
	{
		tmp = ft_spaceserase(f->redi[1]);
		free(f->redi[1]);
		f->redi[1] = tmp;
		f->fd2 = open(f->redi[1], O_RDONLY, 0777);
		f->ret = dup2(f->fd2, 0);
		ft_body_redi2(f);
		close(f->fd2);
	}
}

void		ft_body_redi2(t_shell *f)
{
	f->arg = ft_split(f->redi[0], ' ', f);
	ft_free_matrix(f->redi);
	ft_dollar(f);
	ft_cases(f);
}
