/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redii2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 17:43:53 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/10/12 17:48:55 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_redi_z(t_shell *f, char *tmp)
{
	tmp = ft_strtrim(f->redi[1], " ");
	free(f->redi[1]);
	f->redi[1] = ft_strdup(tmp);
	f->fd2 = open(f->redi[1], O_CREAT | O_WRONLY, 0777);
	if (f->fd2 < 0)
	{
		ft_printf("%s\n", strerror(errno));
		exit(1);
	}
	f->ret = dup2(f->fd2, 1);
	ft_body_redi2(f);
	close(f->fd2);
}

void	ft_redi_x(t_shell *f, char *tmp)
{
	tmp = ft_strtrim(f->redi[1], " ");
	free(f->redi[1]);
	f->redi[1] = ft_strdup(tmp);
	f->fd2 = open(f->redi[1], O_CREAT | O_APPEND | O_WRONLY, 0777);
	if (f->fd2 < 0)
	{
		ft_printf("error :%s\n", strerror(errno));
		exit(1);
	}
	f->ret = dup2(f->fd2, 1);
	ft_body_redi2(f);
	close(f->fd2);
}
