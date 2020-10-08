/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 18:58:15 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/10/08 21:20:13 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			display_msg1(t_shell *f)
{
	if (f->quote == 1)
		ft_putstr("dquote> ");
	else
		ft_putstr("quote> ");
}

int				ft_quotes(t_shell *f)
{
	int i;
	int j;
	int	k;

	f->quote = 0;
	j = 0;
	i = 0;
	k = 0;
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
	return (ft_quotes1(f));
}

int				ft_quotes1(t_shell *f)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (f->line[j] != 0)
	{
		if (f->line[j] == 34 && f->quote == 1)
			i++;
		if (f->line[j] == 39 && f->quote == 2)
			k++;
		j++;
	}
	printf("i = %i\n", i);
	printf("k = %i\n", k);
	printf("quote = %i\n", f->quote);
	if ((i % 2 != 0 && f->quote == 1) || (k % 2 != 0 && f->quote == 2))
		return (1);
	return (0);
}

void			ft_quote2(t_shell *f)
{
	char	*temp;
	int		t;

	printf("ENTRAAA\n");
	t = 0;
	if (ft_strnstr(f->line, "echo", ft_strlen(f->line)))
		t = 1;
	if (t == 1)
		ft_extra(temp, f);
	else
		ft_extra2(temp, f);
}
