/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:20:12 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/09/18 15:23:17 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_extra(char *temp, t_shell *f)
{
	while (1)
	{
		temp = f->line;
		display_msg1(f);
		get_next_line(0, &f->line);
		if (ft_strchr(f->line, '"') != 0)
		{
			f->line = ft_strjoin1(temp, f->line);
			free(temp);
			break ;
		}
		f->line = ft_strjoin1(temp, f->line);
		free(temp);
	}
}

void		ft_extra2(char *temp, t_shell *f)
{
	while (1)
	{
		temp = f->line;
		display_msg1(f);
		get_next_line(0, &f->line);
		if (ft_strchr(f->line, '"') != 0)
		{
			f->line = ft_strjoin2(temp, f->line);
			free(temp);
			break ;
		}
		f->line = ft_strjoin2(temp, f->line);
		free(temp);
	}
}
