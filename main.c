/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:10:01 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/09/28 19:48:43 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void ft_$(char **str, t_shell *f)
{
    int     i;
    int     j;
    char    *tmp;
    char    *tmp2;
    i = 0;
    while (str[i])
    {
        j = 0;
        while (str[i][j])
        {
            if (str[i][j] == '$')
            {
                str[i][j] = 0;
                j++;
                tmp2 = str[i];
                tmp = ft_var(&str[i][j], f);
                free(str[i]);
                str[i] = ft_strjoin(tmp2, tmp);
                while (str[i][j] != '$' && str[i][j])
                    j++;
            }
            j++;
        }
        i++;
    }
}

static	t_shell		*ft_create_struct(t_shell *f, char **env)
{
	int i;

	i = 0;
	if (!(f = malloc(sizeof(t_shell))))
		return (0);
	f->pwd = getcwd(f->pwd, 4096);
	f->c = 32;
	f->flag = 0;
	f->envv = env;
	f->erno = NULL;
	return (f);
}

void    ft_get_user(t_shell *f)
{
	int i;

	i = 0;
    while (f->envv[i])
    {
        if (!ft_strncmp(f->envv[i], "HOME=", 5))
        {
            f->home = ft_strdup(f->envv[i] + 5);
            break;
        }
       i++;
    }
}

void    ft_get_path(t_shell *f)
{
	int i;

	i = 0;
    while (f->envv[i])
    {
        if (!ft_strncmp(f->envv[i], "PATH=", 5))
        {
            f->path = ft_split(f->envv[i] + 5, ':', f);
            break;
        }
       i++;
    }
	ft_get_user(f);
}

int					main(int argc, char **argv, char **env)
{
	int		i;
	t_shell *f;
	char	*proceso;

	i = 0;
	f = ft_create_struct(f, env);
	ft_get_path(f);
	ft_clear(f);
	while (1)
	{
		display_msg();		
		signal(SIGINT, signal_handler);
		signal(SIGQUIT, signal1);
		get_next_line(0, &f->line);
		i = ft_quotes(f);
		if (i == 1)
			ft_quote2(f);
		proceso = f->line;
		f->process = ft_split_cmd(f->line, ";|", f);
		while (*f->process)
		{
			f->arguments = ft_split(*f->process, f->c, f);
			ft_$(f->arguments, f);
			ft_cases(f);
			f->process++;
		}
		free(f->line);
	}
	return (0);
}
