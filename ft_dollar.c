/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-a <glopez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 19:50:20 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/10/14 19:16:17 by glopez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_dollar(t_shell *f)
{
	int		i;
	int		j;
	char	*tmp;
	char	*tmp2;

	i = -1;
	while (f->arg[++i])
	{
		j = 0;
		while (f->arg[i][j] && f->arg[i][j] != '$')
			j++;
		tmp = ft_strndup(f->arg[i], j);
		while (f->arg[i][j] && f->arg[i][j] == '$')
		{
			tmp2 = ft_strjoin(tmp, ft_var(&f->arg[i][++j], f));
			free(tmp);
			tmp = ft_strdup(tmp2);
			free(tmp2);
			while (f->arg[i][j] && f->arg[i][j] != '$' && f->arg[i][j] != ' ')
				j++;
		}
		free(f->arg[i]);
		f->arg[i] = ft_strdup(tmp);
		free(tmp);
	}
}

static void		ft_fill_env(t_shell *f, char **env)
{
	int	i;
	int j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j])
		{
			f->envv[i][j] = env[i][j];
			j++;
		}
		f->envv[i][j] = 0;
		i++;
	}
	f->envv[i] = 0;
}

static int		ft_malloc_matrix(t_shell *f, char **env)
{
	int	i;
	int j;

	i = 0;
	while (env[i])
		i++;
	if (!(f->envv = malloc(sizeof(char *) * (i + 1))))
		return (0);
	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j])
			j++;
		if (!(f->envv[i] = malloc(sizeof(char) * (j + 1))))
			return (0);
		i++;
	}
	ft_fill_env(f, env);
	return (1);
}

t_shell			*ft_create_struct(t_shell *f, char **env)
{
	int i;

	i = 0;
	if (!(f = malloc(sizeof(t_shell))))
		return (0);
	f->pwd = getcwd(f->pwd, 4096);
	f->flag = 0;
	f->flag1 = 0;
	f->flag2 = 0;
	ft_malloc_matrix(f, env);
	f->quote = 0;
	f->p = 0;
	f->i = 0;
	f->z = 0;
	f->x = 0;
	f->c = 0;
	f->a = 0;
	f->b = 0;
	f->k = 0;
	f->statuss = 0;
	f->erno = NULL;
	return (f);
}
