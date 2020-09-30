/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-a <glopez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:10:01 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/09/30 18:31:20 by glopez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void ft_$(t_shell *f)
{
    int     i;
    int     j;
    char    *tmp;
    char    *tmp2;

    i = -1;
    while (f->arguments[++i])
    {
        j = 0;
        while (f->arguments[i][j] && f->arguments[i][j] != '$')
            j++;
        tmp = ft_strndup(f->arguments[i], j);
        while (f->arguments[i][j] && f->arguments[i][j] == '$')
        {
            tmp2 = ft_strjoin(tmp, ft_var(&f->arguments[i][++j], f));
            free(tmp);      
            tmp = ft_strdup(tmp2);
			free(tmp2);
            while (f->arguments[i][j] && f->arguments[i][j] != '$' && f->arguments[i][j] != ' ')
                j++;
        }
		free(f->arguments[i]);
        f->arguments[i] = ft_strdup(tmp);
        free(tmp);
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
	f->p = 0; 
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
		if (get_next_line(0, &f->line) == 0 && !*f->line)
			signal1(1);
		i = ft_quotes(f);
		if (i == 1)
			ft_quote2(f);
		proceso = f->line;
		f->process = ft_split_cmd(f->line, ";|", f);
		while (*f->process)
		{
			f->arguments = ft_split(*f->process, f->c, f);
			ft_$(f);
			ft_cases(f);
			f->process++;
		}
		free(f->line);
	}
	return (0);
}
