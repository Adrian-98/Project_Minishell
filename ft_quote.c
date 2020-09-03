/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 18:58:15 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/09/03 19:55:53 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "minishell.h"

static void	display_msg1(t_shell *f)
{
	if (f->quote == 1)
		ft_putstr("dquote> ");
	else
		ft_putstr("quote> ");
}

int		ft_quotes(t_shell *f)
{
	int i;
	int j;

	j = 0;
	i = 0;

	while (f->line[j] != 0)
	{
		if (f->line[j] == 34)
			f->quote = 1;
		else if (f->line[j] == 39)
			f->quote = 2;
		else if (f->quote == 1 || f->quote == 2)
			break ;
		j++;
	}
	j = 0;
	while (f->line[j] != 0)
	{
		if (f->line[j] == 34 || f->line[j] == 39)
			i++;
		j++;
	}
	if (i % 2 != 0)
		return (1);
	return (0);
}

void	ft_quote1(t_shell *f)
{
	while (1)
	{
		display_msg1(f);
		get_next_line(0, &f->line);
		free(f->line);
	}
}

