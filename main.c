/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:10:01 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/08/29 12:38:22 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"


static	t_shell		*ft_create_struct(t_shell *f)
{
	if (!(f = malloc(sizeof(t_shell))))
		return 0;
	f->path = getcwd(f->path, 4096);
	f->c = 32;
	return(f);
}

int main(int argc, char **argv, char **env)
{
	t_shell *f;

	f = NULL;
	f = ft_create_struct(f);

	while (1)
	{
		display_msg(f);			
		get_next_line(0, &f->line);
		f->line = ft_spaceserase(f->line);
		ft_cases(f);
		free(f->line);
	}
	return 0;
}
