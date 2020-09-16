/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:10:01 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/09/16 20:23:09 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"


static	t_shell		*ft_create_struct(t_shell *f)
{
	if (!(f = malloc(sizeof(t_shell))))
		return 0;
	f->pwd = getcwd(f->pwd, 4096);
	f->c = 32;
	f->flag = 0;
	return(f);
}

void	ft_get_path(t_shell *f)
{
	while (*f->envv)
	{
		if (!ft_strncmp(*f->envv, "PATH=", 5))
		{
			f->path = ft_split1(*f->envv + 5, ':', f);
			break;
		}
		f->envv++;
	}
}

int main(int argc, char **argv, char **env)
{
	int i;
	t_shell *f;
	char	*proceso;
	 char   a[50] = "hello\\n";
	// printf("%s\n", a);
	// exit(0);

	i = 0;
	f = NULL;
	f = ft_create_struct(f);
	f->envv = env;
	ft_get_path(f);
	while (1)
	{
		display_msg(f);			
		get_next_line(0, &f->line);
		i = ft_quotes(f);
		if (i == 1)
			ft_quote2(f);
		proceso = f->line;
		f->process = ft_split_cmd(f->line, ";|", f);
		while (*f->process)
		{
			f->arguments = ft_split(*f->process, f->c, f);
			ft_cases(f);
			f->process++;
		}
		free(f->line);
	}
	return 0;
}