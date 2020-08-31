/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:33:02 by adrian            #+#    #+#             */
/*   Updated: 2020/08/29 12:56:00 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cases(t_shell *f)
{
	int	i = 0;
	f->arguments = ft_split(f->line, f->c);
	if (ft_strncmp("exit", f->arguments[0], ft_strlen(f->arguments[0]))== 0)
		ft_exit(f);
	else if (ft_strncmp("pwd", f->arguments[0], ft_strlen(f->arguments[0])) == 0)
	{
		while (f->arguments[i] != 0)
			i++;
		if (i > 1)
			ft_too_many(f);
		else
			ft_pwd(f);
	}
	else
		ft_404(f);
}
