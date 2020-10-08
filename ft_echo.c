/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-a <glopez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:33:02 by adrian            #+#    #+#             */
/*   Updated: 2020/10/08 19:15:46 by glopez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_var(char *str, t_shell *f)
{
	char	*str1;
    char    *str2;
	int		i;
	int		j;
	int		k;

	if (!str)
		return (0);
	j = 0;
	i = 0;
    if (str[i] == '?')
    {
        i++;
        j = i;
        str1 = ft_itoa(f->statuss);
        while (str[j] && str[j] != '$')
            j++;
        str2 = ft_strndup(&str[i], j);
        ft_strlcat(str1, str2, j + ft_strlen(str1));
        free(str2);
        return (str1);
    }
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
    //ft_free_matrix(f->arguments);
}
