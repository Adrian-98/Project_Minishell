/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redii2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 17:43:53 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/10/19 20:12:15 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_redi_z(t_shell *f, char *tmp)
{
	tmp = ft_spaceserase(f->redi[1]);
	free(f->redi[1]);
	f->redi[1] = tmp;
	f->fd2 = open(f->redi[1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (f->fd2 < 0)
	{
		ft_printf("%s\n", strerror(errno));
		close(f->fd2);
		return ;
	}
	f->ret = dup2(f->fd2, 1);
	ft_body_redi2(f);
	close(f->fd2);
}

void	ft_redi_x(t_shell *f, char *tmp)
{
	tmp = ft_spaceserase(f->redi[1]);
	free(f->redi[1]);
	f->redi[1] = tmp;
	f->fd2 = open(f->redi[1], O_CREAT | O_APPEND | O_WRONLY, 0640);
	if (f->fd2 < 0)
	{
		ft_printf("error :%s\n", strerror(errno));
		close(f->fd2);
		return ;
	}
	f->ret = dup2(f->fd2, 1);
	ft_body_redi2(f);
	close(f->fd2);
}

void	ft_redi_v(t_shell *f, char *tmp)
{
	tmp = ft_spaceserase(f->redi[1]);
	free(f->redi[1]);
	f->redi[1] = tmp;
	f->fd2 = open(f->redi[1], O_RDONLY, 0640);
	if (f->fd2 < 0)
	{
		ft_printf("error %s:%s\n", f->redi[1], strerror(errno));
		close(f->fd2);
		return ;
	}
	tmp = ft_spaceserase(f->redi[2]);
	free(f->redi[2]);
	f->redi[2] = tmp;
	f->aux = open(f->redi[2], O_CREAT | O_TRUNC | O_WRONLY, 0640);
	if (f->aux < 0)
	{
		ft_printf("error %s:%s\n", f->redi[2], strerror(errno));
		close(f->aux);
		return ;
	}
	f->ret = dup2(f->fd2, 0);
	f->ret = dup2(f->aux, 1);
	ft_body_redi2(f);
	close(f->fd2);
}

void	ft_redi_c(t_shell *f, char *tmp)
{
	tmp = ft_spaceserase(f->redi[1]);
	free(f->redi[1]);
	f->redi[1] = tmp;
	f->fd2 = open(f->redi[1], O_RDONLY, 0640);
	if (f->fd2 < 0)
	{
		ft_printf("error %s:%s\n", f->redi[1], strerror(errno));
		close(f->fd2);
		return ;
	}
	f->ret = dup2(f->fd2, 0);
	ft_body_redi2(f);
	close(f->fd2);
}
