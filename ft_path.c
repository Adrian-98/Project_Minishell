/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:18:24 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/09/24 20:15:56 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_msg(t_shell *f)
{
	ft_putstr(" \033[31m♛");
	ft_putstr("\033[0m\033[34m☻\033[0m\033[35m♛\033[0m➣% ");
}

void	ft_pwd(t_shell *f)
{
	int i;

	i = 0;
	while (f->arguments[i])
		i++;
	if (i >= 2)
		ft_too_many(f);
	else
	{
		f->pwd = getcwd(f->pwd, 4096);
		ft_printf("%s\n", f->pwd);
	}
}
