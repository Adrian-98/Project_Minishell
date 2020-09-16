/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 18:58:15 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/09/16 20:16:25 by amunoz-p         ###   ########.fr       */
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
	int	k;

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

int		ft_quotes1(t_shell *f)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (f->line[j] != 0)
	{
		if (f->line[j] == 34)
			i++;
		if (f->line[j] == 39)
			k++;
		j++;
	}
	if (i % 2 != 0 || k % 2 != 0)
		return (1);
	return (0);
}

void	ft_quote2(t_shell *f)
{
	char	*temp;
	int		t;

	t = 0;
	if (ft_strnstr(f->line, "echo", ft_strlen(f->line)))
		t = 1;
	printf("valor de t =%i\n", t);
	if (t == 1)
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
	else
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

