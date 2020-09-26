/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 17:58:40 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/09/26 13:34:43 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_already(t_shell *f, char *aux)
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

int			ft_export_while(t_shell *f)
{
	int		i;
	char	**tmp;

	i = 1;
	while (f->arguments[i] != 0)
	{
		if (!(ft_strchr(f->arguments[i], '=')))
			return (0);
		ft_export(f, f->arguments[i], tmp);
		i++;
	}
	return (0);
}

int		ft_export(t_shell *f, char *str, char **tmp)
{
	char	*aux;
	char	*aux1;
	int		i;
	int		j;
	int		k;


	i = 0;
	while (f->envv[i])
		i++;
	if (!(tmp = malloc(sizeof(char *) * (i + 2))))
		return (0);
	k = i + 1;
	i = 0;
	if (!(str))
		return (0);
	aux = ft_strndup(str, ft_strchr(str, '=') - str + 1);
	aux1 = ft_strdup(ft_strrchr(str, '=') + 1);
	i = ft_already(f, aux);
	j = -1;
	if (i >= 0)
	{
		tmp[i] = ft_strjoin(aux, aux1);
		while (++j < i)
			tmp[j] = ft_strdup(f->envv[j]);
		while (++i < k)
			tmp[i] = ft_strdup(f->envv[++j]);
	}
	else
	{
		i = -1;
		while (++i < k - 2)
		{
			tmp[i] = ft_strdup(f->envv[i]);
		}
		tmp[i] = ft_strjoin(aux, aux1);
		i++;
		tmp[i] = ft_strdup(f->envv[i - 1]);
		tmp[++i] = 0;
	}
	free(aux);
	free(aux1);
	f->envv = tmp;
	ft_get_path(f);
	return (0);
}
