/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 17:58:40 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/09/23 18:12:49 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int		ft_already(t_shell *f, char *aux)
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

int		ft_export(t_shell *f)
{
	char	**tmp;
	char	*aux;
	char	*aux1;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (f->envv[i])
	{
		printf("%i --%s\n", i, f->envv[i]);
		i++;
	}
	printf(" original^^^^^^^-----------------------------\n");
	if (!(tmp = malloc(sizeof(char *) * (i + 1))))
		return (0);
	k = i + 1;
	i = 0;
	while (f->arguments[i])
		i++;
	if (i > 2 || f->arguments[1] == 0)
		return (0);
	aux = ft_strndup(f->arguments[1],
		ft_strchr(f->arguments[1], '=') - f->arguments[1] + 1);
	aux1 = ft_strdup(ft_strrchr(f->arguments[1], '=') + 1);
	i = ft_already(f, aux);
	printf("valor de i =%i\n", i);
	j = -1;
	if (i >= 0)
	{
		tmp[i] = ft_strjoin(aux, aux1);
		free(aux);
		free(aux1);
		while (++j < i)
		{
			tmp[j] = ft_strdup(f->envv[j]);
			printf("%i-->%s\n", j, tmp[j]);
		}
		printf("%i-->%s\n", i, tmp[i]);
		while (++i < k)
		{
			tmp[i] = ft_strdup(f->envv[++j]);
			printf("%i-->%s\n", i, tmp[j]);
		}
		printf("-----------------------------\n");
		i = 0;
		while (tmp[i])
		{
			printf("%s\n", tmp[i]);
			i++;
		}
	}
	return (0);
}
