/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:10:01 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/09/03 19:50:31 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"


static	t_shell		*ft_create_struct(t_shell *f)
{
	if (!(f = malloc(sizeof(t_shell))))
		return 0;
	f->path = getcwd(f->path, 4096);
	f->c = 32;
	f->quote = 0;
	return(f);
}



int main(int argc, char **argv, char **env)
{
	int i;
	t_shell *f;

	i = 0;
	f = NULL;
	f = ft_create_struct(f);

	while (1)
	{
		display_msg(f);			
		get_next_line(0, &f->line);
		i = ft_quotes(f);
		if (i == 1)
			ft_quote2(f);	
		else
		{
			f->arguments = ft_split(f->line, f->c);
			ft_cases(f);
		}
		free(f->line);
	}
	return 0;
}
