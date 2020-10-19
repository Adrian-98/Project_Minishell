/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 17:58:40 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/10/19 16:39:51 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ft_already(t_shell *f, char *aux)
{
	int i;

	i = 0;
	while (f->envv[i])
	{
		if (!ft_strncmp(f->envv[i], aux,
			ft_strlen(aux)))
			return (i);
		i++;
	}
	return (-1);
}

int				ft_export_while(t_shell *f)
{
	int		i;
	char	**tmp;

	i = 1;
	while (f->arg[i] != 0)
	{
		if (!(ft_strchr(f->arg[i], '=')))
			return (0);
		ft_export(f, f->arg[i], tmp);
		i++;
	}
	return (0);
}

static char		**ft_export2(char *aux, char **tmp, char *aux1, t_shell *f)
{
	f->b = -1;
	if (f->a >= 0)
	{
		tmp[f->a] = ft_strjoin(aux, aux1);
		while (++f->b < f->a)
			tmp[f->b] = ft_strdup(f->envv[f->b]);
		while (++f->a < f->k)
			tmp[f->a] = ft_strdup(f->envv[++f->b]);
		tmp[f->a] = 0;
	}
	else
	{
		f->a = -1;
		while (++f->a < f->k - 2)
		{
			tmp[f->a] = ft_strdup(f->envv[f->a]);
		}
		tmp[f->a] = ft_strjoin(aux, aux1);
		f->a++;
		tmp[f->a] = ft_strdup(f->envv[f->a - 1]);
		tmp[++f->a] = 0;
	}
	return (tmp);
}

int				ft_export(t_shell *f, char *str, char **tmp)
{
	char	*aux;
	char	*aux1;

	while (f->envv[f->a])
		f->a++;
	if (!(tmp = malloc(sizeof(char *) * (f->a + 2))))
		return (0);
	f->k = f->a + 1;
	f->a = 0;
	if (!(str))
		return (0);
	aux = ft_strndup(str, ft_strchr(str, '=') - str + 1);
	aux1 = ft_strdup(ft_strrchr(str, '=') + 1);
	f->a = ft_already(f, aux);
	tmp = ft_export2(aux, tmp, aux1, f);
	free(aux);
	free(aux1);
	ft_free_matrix(f->envv);
	f->envv = tmp;
	if (f->path)
		ft_free_matrix(f->path);
	ft_get_path(f);
	return (0);
}
