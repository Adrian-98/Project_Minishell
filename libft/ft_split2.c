/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:00:29 by glopez-a          #+#    #+#             */
/*   Updated: 2020/10/12 18:17:21 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_rows2(char const *s, char c, int i, int rows)
{
	int j;

	j = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
			j = 1;
		if (s[i] == '"')
		{
			i++;
			while (s[i] && s[i] != '"')
				i++;
		}
		if (s[i] == c)
		{
			while (s[i] && s[i] == c)
				i++;
			if (s[i])
				rows++;
		}
		else
			i++;
	}
	return (rows + j);
}

static int			ft_rows(char const *s, char c)
{
	int i;
	int rows;

	i = 0;
	rows = 0;
	while (s[i] && s[i] == c)
		i++;
	i = ft_rows2(s, c, i, rows);
	return (i);
}

static char			*ft_str_malloc(char const *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != c)
	{
		if (s[i] == '"')
		{
			i++;
			while (s[i] && s[i] != '"')
				i++;
		}
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ft_strlcpy(str, s, i + 1);
	return (str);
}

char				**ft_split2(char const *s, char c)
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
		while (*s == c)
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
