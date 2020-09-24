/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 19:55:12 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/09/24 17:29:50 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_unset(t_shell *f)
{
	char	**temporal;
	char	*aux;
	char	*aux1;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (f->envv[i])
	{
		printf("%i-->%s\n", i, f->envv[i]);
		i++;
	}
	printf("----------------------\n");
	if (!(temporal = malloc(sizeof(char *) * (i + 1))))
		return (0);
	printf("----------------------\n");
	k = i;
	i = 0;
	while (f->arguments[i])
		i++;
	if (i > 2 || f->arguments[1] == 0)
		return (0);
	aux = ft_strndup(f->arguments[1],
		ft_strchr(f->arguments[1], '=') - f->arguments[1] + 1);
	aux1 = ft_strdup(ft_strrchr(f->arguments[1], '=') + 1);
	i = ft_already(f, aux);
	j = -1;
	while (++j < i)
		temporal[j] = ft_strdup(f->envv[j]);
	while (i++ < k)
		temporal[i] = ft_strdup(f->envv[j++]);
	while (temporal[i])
	{
		printf("%i-->%s\n", i, temporal[i]);
		i++;
	}

	return (0);
}
