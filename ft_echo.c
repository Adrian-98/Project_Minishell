/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:33:02 by adrian            #+#    #+#             */
/*   Updated: 2020/09/01 19:58:49 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo_var(t_shell *f, int i)
{
	char	*str;
	char	*str1;
	int		j;
	int		k;

	j = 0;
	str = &f->arguments[i][1];

	while (f->envv[j])
	{
		k = 0;
		//printf("%s\n", f->envv[j]);
		while (f->envv[j][k] != '=')
			k++;
		if (ft_strncmp(str, f->envv[j], k) == 0 && ft_strlen(str) == k)
		{
			str1 = ft_strchr(f->envv[j], '=');
			str1++;
			printf("%s ", str1);
		}
		j++;
	}
}

void	ft_echo(t_shell *f)
{
	int	i;
	int	j;

	i = 1;
	//printf("hola");
	//if (ft_strncp,f->arguments)
	while (f->arguments[i])
	{
		if (*f->arguments[i] == '$')
			ft_echo_var(f, i);
		else
			printf("%s ", f->arguments[i]);
		i++;
	}
	printf("\n");
}