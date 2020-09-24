/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 19:55:12 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/09/24 18:29:12 by amunoz-p         ###   ########.fr       */
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
	// printf("valor str %s\n",  str);
	while (f->envv[i])
	{
		// printf("%i-->%s\n", i, f->envv[i]);
		i++;
	}
	//  printf("----------------------\n");
	if (!(tmp = malloc(sizeof(char *) * (i + 1))))
		return (0);
	k = i;
	// printf("valor de k= %i\n", k);
	i = 0;
	if ((i = ft_already(f, str)) == -1)
		return (0);
	// printf("valor de i= %i\n", i);
	j = -1;
	while (++j < i)
	{	
		tmp[j] = ft_strdup(f->envv[j]);
		// printf("%i-->%s\n", j, tmp[j]);
	}
	while (i++ < k)
	{
		tmp[i - 1] = ft_strdup(f->envv[++j]);
		// printf("--<%i-->%s\n", i, tmp[i - 1]);
	}
	i = 0;
	// while (tmp[i])
	// {
	// printf("%i-->%s\n", i, tmp[i]);
	// 	i++;
	// }
	f->envv = tmp;
	ft_get_path(f);

	return (0);
}
