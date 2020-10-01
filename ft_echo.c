/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-a <glopez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:33:02 by adrian            #+#    #+#             */
/*   Updated: 2020/10/01 17:21:45 by glopez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *ft_var(char *str, t_shell *f)
{
    char    *str1;
    int     i;
    int     j;
    int     k;

    if (!str)
        return (0);
    j = 0;
    i = 0;
    while (str[i] && str[i] != '$' && str[i] != ' ')
        i++;
    while (f->envv[j])
    {
        k = 0;
        while (f->envv[j][k] != '=')
            k++;     
        if (ft_strncmp(str, f->envv[j], k) == 0 && i == k)
        {
            str1 = ft_strchr(f->envv[j], '=');
            str1++;
            return (str1);
        }
        j++;
    }
    return ("");
}

void	ft_echo(t_shell *f)
{
	int i;
	int j;

	i = 1;
	while (f->arguments[i])
	{
		ft_printf("%s ", f->arguments[i]);
		i++;
	}
	ft_printf("\n");
}
