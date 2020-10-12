/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_user_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 17:53:42 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/10/12 17:56:01 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_get_user(t_shell *f)
{
	int i;

	i = 0;
	while (f->envv[i])
	{
		if (!ft_strncmp(f->envv[i], "HOME=", 5))
		{
			f->home = ft_strdup(f->envv[i] + 5);
			break ;
		}
		i++;
	}
}

void	ft_get_path(t_shell *f)
{
	int i;

	i = 0;
	while (f->envv[i])
	{
		if (!ft_strncmp(f->envv[i], "PATH=", 5))
		{
			f->path = ft_split(f->envv[i] + 5, ':', f);
			break ;
		}
		i++;
	}
	ft_get_user(f);
}

void 	ft_body(t_shell *f)
{
	f->arguments = ft_split(f->pipes[f->i], ' ', f);
	ft_$(f);
	ft_cases(f);
}

int 	ft_count_pipes(t_shell *f)
{
	while(f->pipes[f->p])
		f->p++;
	return (f->p);
}
