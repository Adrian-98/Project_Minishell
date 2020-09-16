/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 18:58:15 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/09/16 18:27:00 by amunoz-p         ###   ########.fr       */
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

int		ft_quotes(t_shell *f, char *proceso)
{
	int i;
	int j;
	int	k;

	j = 0;
	i = 0;
	k = 0;
	while (proceso[j] != 0)
	{
		if (proceso[j] == 34)
			f->quote = 1;
		else if (proceso[j] == 39)
			f->quote = 2;
		else if (f->quote == 1 || f->quote == 2)
			break ;
		j++;
	}
	return (ft_quotes1(f, proceso));
}

int		ft_quotes1(t_shell *f, char *proceso)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (proceso[j] != 0)
	{
		if (proceso[j] == 34)
			i++;
		if (proceso[j] == 39)
			k++;
		j++;
	}
	if (i % 2 != 0 || k % 2 != 0)
		return (1);
	return (0);
}

void	ft_quote2(t_shell *f)
{
	while (1)
	{
		display_msg1(f);
		get_next_line(0, &f->line);
		free(f->line);
	}
}

