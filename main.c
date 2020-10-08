/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-a <glopez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:10:01 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/10/08 17:24:55 by glopez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_$(t_shell *f)
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
	f->flag = 0;
	f->envv = env;
	f->p = 0; 
	f->i = 0;
	f->z = 0;
	f->x = 0;
	f->c = 0;
	f->statuss = 0;
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
	//printf("%i---valor de pipes=%s\n", f->i, f->pipes[f->i]);
	f->arguments = ft_split(f->pipes[f->i], ' ', f);
	ft_$(f);
	ft_cases(f);
}

int 	ft_count_pipes(t_shell *f)
{
	while(f->pipes[f->p])
		f->p++;
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
		f->process = ft_split2(f->line, ';');
		int	cv;
		cv = 0;
		while (f->process[cv])
		{
			f->pipes = ft_split2(f->process[cv], '|');
			f->save[0] = dup(STDIN_FILENO);
			f->save[1] = dup(STDOUT_FILENO);
			f->i = 0;
			while (f->pipes[f->i])
			{
				//printf(" ANTES z=%i x = %i c = %i\n", f->z, f->x, f->c);
				ft_redi(f->pipes[f->i], f);
				//printf(" DESPUES z=%i x = %i c = %i\n", f->z, f->x, f->c);
				if (f->pipes[f->i + 1] && f->z == 0 && f->x == 0)
				{
					//printf("\n%ientra\n", f->i);
					pipe(f->fd1);
					f->pid = fork();
					if(f->pid == 0)             
					{
						dup2(f->fd1[WRITE_END], STDOUT_FILENO);
						if (f->c == 1)
						{
							ft_body_redi(f);
						}
						else
							ft_body(f);
						exit(0);
					}
					else if  (f->pid > 0)
					{
						waitpid(f->pid, &f->status, 0);
						close(f->fd1[WRITE_END]);
						dup2(f->fd1[READ_END], STDIN_FILENO);
						close(f->fd1[READ_END]);
					}
				}
				else if (f->z == 0 && f->x == 0 && f->c == 0)
					ft_body(f);
				else 
					ft_body_redi(f);
				f->i++;

			}
			dup2(f->save[0], STDIN_FILENO);
			dup2(f->save[1], STDOUT_FILENO);
			ft_free_matrix(f->pipes);
			cv++;
		}
		ft_free_matrix(f->process);
		free(f->line);
		// system("leaks minishell");
        // exit(0);
	}
	return (0);
}
