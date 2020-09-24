/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:33:02 by adrian            #+#    #+#             */
/*   Updated: 2020/09/24 20:15:46 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *ft_var(char *str, t_shell *f)
{
	char	*str1;
	int		j;
	int		k;

	if (!str)
		return (0);
	j = 0;
	if ((str1 = ft_strchr(str, '$')) != 0)
		*str1 = 0;
	while (f->envv[j])
	{
		k = 0;
		while (f->envv[j][k] != '=')
			k++;
		if (ft_strncmp(str, f->envv[j], k) == 0 && ft_strlen(str) == k)
		{
			str1 = ft_strchr(f->envv[j], '=');
			str1++;
			return (str1);
		}
		j++;
	}
	return (0);
}

void	ft_echo(t_shell *f)
{
	int i;
	int j;

	i = 1;
	//ft_printf("hola");
	//if (ft_strncp,f->arguments)
	while (f->arguments[i])
	{
		ft_printf("%s ", f->arguments[i]);
		i++;
	}
	ft_printf("\n");
}
