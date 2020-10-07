/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:33:02 by adrian            #+#    #+#             */
/*   Updated: 2020/10/07 17:53:42 by amunoz-p         ###   ########.fr       */
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
	if (ft_strcmp(f->arguments[1], "-n") == 0)
		i++;
	while (f->arguments[i])
	{
        if (!f->arguments[i + 1])
		    ft_printf("%s", f->arguments[i]);
        else
		    ft_printf("%s ", f->arguments[i]);
		i++;
	}
	if (ft_strcmp(f->arguments[1], "-n") == 0)
		ft_printf("%%");
	ft_printf("\n");
}
