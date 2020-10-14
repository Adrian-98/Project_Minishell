/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:10:01 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/10/14 17:38:54 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_pipes2(t_shell *f)
{
	pipe(f->fd1);
	f->pid = fork();
	if (f->pid == 0)
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
	else if (f->pid > 0)
	{
		waitpid(f->pid, &f->status, 0);
		close(f->fd1[WRITE_END]);
		dup2(f->fd1[READ_END], STDIN_FILENO);
		close(f->fd1[READ_END]);
	}
}

void			ft_pipes(t_shell *f)
{
	while (f->pipes[f->i])
	{
		ft_redi(f->pipes[f->i], f);
		if (f->pipes[f->i + 1] && f->z == 0 && f->x == 0)
		{
			ft_pipes2(f);
		}
		else if (f->z == 0 && f->x == 0 && f->c == 0)
			ft_body(f);
		else
			ft_body_redi(f);
		f->i++;
	}
}

void			main2(t_shell *f)
{
	int cv;

	cv = 0;
	while (f->process[cv])
	{
		f->pipes = ft_split2(f->process[cv], '|');
		f->save[0] = dup(STDIN_FILENO);
		f->save[1] = dup(STDOUT_FILENO);
		f->i = 0;
		ft_pipes(f);
		dup2(f->save[0], STDIN_FILENO);
		dup2(f->save[1], STDOUT_FILENO);
		ft_free_matrix(f->pipes);
		cv++;
	}
}

int				main(int argc, char **argv, char **env)
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
		if (get_next_line(0, &f->line) == 0)
			signal1(1);
		i = ft_quotes(f);
		if (i == 1)
			ft_quote2(f);
		proceso = f->line;
		f->process = ft_split2(f->line, ';');
		main2(f);
		ft_free_matrix(f->process);
		free(proceso);
	}
	return (0);
}
