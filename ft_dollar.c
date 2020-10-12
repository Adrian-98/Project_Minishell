/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 19:50:20 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/10/12 20:08:11 by amunoz-p         ###   ########.fr       */
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
	f->envv = env;
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
