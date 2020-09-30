/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 19:55:12 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/09/24 18:33:04 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_unset_while(t_shell *f)
{
	int		i;
	char	**tmp;

	i = 1;
	while (f->arguments[i] != 0)
	{
		ft_unset(f, f->arguments[i], tmp);
		i++;
	}
	return (0);
}

int			ft_unset(t_shell *f, char *str, char **tmp)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (f->envv[i])
		i++;
	if (!(tmp = malloc(sizeof(char *) * (i + 1))))
		return (0);
	k = i;
	i = 0;
	if ((i = ft_already(f, str)) == -1)
		return (0);
	j = -1;
	while (++j < i)
		tmp[j] = ft_strdup(f->envv[j]);
	while (i++ < k)
		tmp[i - 1] = ft_strdup(f->envv[++j]);
	f->envv = tmp;
	ft_get_path(f);
	return (0);
}