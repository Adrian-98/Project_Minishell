/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 17:58:40 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/09/22 20:37:04 by amunoz-p         ###   ########.fr       */
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
	return (0);
}

int		ft_export(t_shell *f)
{
	char	**tmp;
	char	*aux;
	char 	*aux1;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (f->envv[i])
	{
		printf("%i --%s\n", i, f->envv[i]);
		i++;
	}
	if (!(tmp = malloc(sizeof(i + 2))))
		return (0);
	k = i + 2;
	i = 0;
	while (f->arguments[i])
		i++;
	if (i > 2 || f->arguments[1] == 0)
		return (0);
	aux = ft_strndup(f->arguments[1],
	ft_strchr(f->arguments[1], '=') - f->arguments[1] + 1);
	aux1 = ft_strdup(ft_strrchr(f->arguments[1], '=') + 1);
	printf("aux     %s\naux1      %s\n", aux, aux1);
	i = ft_already(f, aux);
	printf("aux     %s\naux1      %s\n", aux, aux1);
	printf("%i\n", i);
	j = 0;
	if (i != 0)
	{


		while (j < i)
		{
			tmp[j] = ft_strdup(f->envv[j]);
			printf("%i--%s\n", j, tmp[j]);
			j++;
		}
		printf("valor de j%i\n", j);
		tmp[i] = ft_strjoin("OLD", f->envv[i]);
		printf("%i--%s\n", i, tmp[i]);

		tmp[j + 1] = ft_strjoin(aux, aux1);
		printf("%i--%s\n", i, tmp[j + 1]);
		//printf("valor de i=%i\nvalor de k=%i\n valor de j%i\n", i, k, j);
		// while (i++ < k)
		// 	tmp[i] = ft_strdup(f->envv[j++]);
		// tmp[k] = 0;
	}
	// while (*tmp++)
	// 	printf("%s\n", *tmp);
	return (0);
}
