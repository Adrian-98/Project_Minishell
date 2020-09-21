/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:10:01 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/09/21 20:27:41 by amunoz-p         ###   ########.fr       */
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
	if (!(f = malloc(sizeof(t_shell))))
		return (0);
	f->pwd = getcwd(f->pwd, 4096);
	f->c = 32;
	f->flag = 0;
	f->envv = env;
	return (f);
}

void    ft_get_path(t_shell *f)
{
    char    **str;
    pid_t   id;
    str = malloc(sizeof(char *) * 2);
    str[0] = "clear";
    str[1] = 0;
    while (*f->envv)
    {
        if (!ft_strncmp(*f->envv, "PATH=", 5))
        {
            f->path = ft_split(*f->envv + 5, ':', f);
            break;
        }
        f->envv++;
    }
    id = fork();
    if (id == 0)
        execve("/usr/bin/clear", str, f->envv);
    wait(0);
}

int					main(int argc, char **argv, char **env)
{
	int		i;
	t_shell *f;
	char	*proceso;

	i = 0;
	f = ft_create_struct(f, env);
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
			ft_$(f->arguments, f);
			ft_cases(f);
			f->process++;
		}
		free(f->line);
	}
	return (0);
}
