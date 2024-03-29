/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-a <glopez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 19:55:12 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/10/14 21:18:01 by glopez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_unset_while(t_shell *f)
{
	int		i;
	char	**tmp;

	i = 1;
	while (f->arg[i] != 0)
	{
		ft_unset(f, f->arg[i], tmp);
		i++;
	}
	return (0);
}

int			ft_unset(t_shell *f, char *str, char **tmp)
{
	int		i;
	int		j;

	i = 0;
	while (f->envv[i])
		i++;
	if (!(tmp = malloc(sizeof(char *) * (i + 1))))
		return (0);
	f->k = i;
	i = 0;
	str = ft_strjoin(str, "=");
	if ((i = ft_already(f, str)) == -1)
		return (0);
	free(str);
	j = -1;
	while (++j < i)
		tmp[j] = ft_strdup(f->envv[j]);
	while (i++ < f->k)
		tmp[i - 1] = ft_strdup(f->envv[++j]);
	ft_free_matrix(f->envv);
	f->envv = tmp;
	if (f->path)
		ft_free_matrix(f->path);
	ft_get_path(f);
	return (0);
}
