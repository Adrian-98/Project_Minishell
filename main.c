/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:10:01 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/09/30 22:12:21 by amunoz-p         ###   ########.fr       */
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
	f->i = 0;
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

void 	ft_body(t_shell *f)
{
	f->arguments = ft_split(f->pipes[f->i], f->c, f);
	//ft_$(f->arguments, f);
	ft_cases(f);
}

int 	ft_count_pipes(t_shell *f)
{
	while(f->pipes[f->p])
	{
		//printf("valor de cada pipe = %s\n", f->pipes[f->p]);
		f->p++;
	}
	return (f->p);
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
		f->process = ft_split(f->line, ';', f);
		int	cv;
		cv = 0;
		while (f->process[cv])
		{
			// printf("process = [%s]\n", f->process[cv]);
			f->pipes = ft_split(f->process[cv], '|', f);
			//f->save[0] = dup(STDIN_FILENO);
			//f->save[1] = dup(STDOUT_FILENO);
			f->i = 0;
			while (f->pipes[f->i])
			{
				// printf("valor de pipes = %s\n", f->pipes[f->i]);
				if (f->pipes[f->i + 1])
				{
					f->pid = fork();
					// printf("entra en pipes\n");
					pipe(f->fd1);
					if(f->pid == 0)             
					{
						close(f->fd1[READ_END]);
						dup2(f->fd1[WRITE_END], STDOUT_FILENO); 
						ft_body(f);
						exit(0);
					}
					else if  (f->pid > 0)
					{
						
						close(f->fd1[WRITE_END]);
						dup2(f->fd1[READ_END], STDIN_FILENO);	
					}
				}
				else
				{
					// printf("GGGGGGGGGGGGGAAAAAAA\n");
					ft_body(f);
				}
				f->i++;
				dup2(f->save[0], STDIN_FILENO);
				dup2(f->save[1], STDOUT_FILENO);
			}
			free(f->pipes);
			cv++;
			// printf("\ncuantas veces entra en process = %i\n", cv);
		}
		free(f->line);
	}
	return (0);
}
