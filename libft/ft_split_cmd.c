/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-a <glopez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 18:47:21 by glopez-a          #+#    #+#             */
/*   Updated: 2020/09/11 19:41:16 by glopez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_rows(char const *s, char *c)
{
	int i;
	int rows;

	i = 0;
	rows = 0;

	while (s[i] && (s[i] == c[0] || s[i] == c[1]))
	{
		i++;
		while (s[i] == ' ')
			i++;
	}	
	while (s[i])
	{
		if (s[i] && s[i] != c[0] && s[i] != c[1])
			rows++;
		while (s[i] && s[i] != c[0] && s[i] != c[1])
			i++;
		if (s[i] == c[0] || s[i] == c[1])
		{
			while (s[i] && (s[i] == c[0] || s[i] == c[1]))
				i++;
		}
		else
			i++;
	}
	return (rows);
}

static	char	*ft_str_malloc(char const *s, char *c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != c[0] && s[i] != c[1])
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ft_strlcpy(str, s, i + 1);
	return (str);
}

char			**ft_split_cmd(char const *s, char *c)
{
	int		rows;
	int		i;
	char	**tab;

	if (!s)
		return (NULL);
	rows = ft_rows(s, c);
	i = -1;
	if (!(tab = malloc(sizeof(char *) * (rows + 1))))
		return (NULL);
	while (++i < rows)
	{
		while (*s == c[0] || *s == c[1])
			s++;
		if (!(tab[i] = ft_str_malloc(s, c)))
		{
			while (i > 0)
				free(tab[i--]);
			free(tab);
			return (NULL);
		}
		s += ft_strlen(tab[i]);
	}
	tab[i] = 0;
	return (tab);
}
