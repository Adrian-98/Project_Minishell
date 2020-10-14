/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-a <glopez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 18:34:32 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/10/14 19:27:44 by glopez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_env(t_shell *f)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (!f->path)
		ft_printf("env: No such file or directory\n");
	else
	{
		while (f->path[i])
		{
			if (!(ft_strncmp(f->path[i], "/usr/bin", 8)))
				j = 1;
			i++;
		}
		i = 0;
		if (j == 1)
			while (f->envv[i])
			{
				ft_printf("%s\n", f->envv[i]);
				i++;
			}
		else
			ft_printf("env: No such file or directory\n");
	}
}
