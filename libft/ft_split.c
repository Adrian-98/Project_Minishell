/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-a <glopez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:00:29 by glopez-a          #+#    #+#             */
/*   Updated: 2019/11/14 17:35:38 by glopez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	int	ft_rows(const char *s, char c)
{
	int i;
	int size;

	if (!s)
		return (-1);
	i = 0;
	size = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '"')
		{
			i++;
			while (s[i] != '"')
				i++;
			i++;
			size++;
		}
		else if (s[i] != c)
		{
			size++;
			while (s[i] != c && s[i] != '\0' && s[i] != '"')
				i++;
		}
		else
			i++;
	}
	return (size);
}

static	char	*ft_str_malloc(char const *s, char c, int k, t_shell *f)
{
	int		i;
	char	*str;

	i = 0;
	if (s[i + k] == '"')
	{
		i++;
		while (s[i + k] != '"')
			i++;
		f->flag = 1;
		i -= 1;
	}
	else
	{
		while (s[i + k] && s[i + k] != c && s[i + k] != '"')
			i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (f->flag == 1)
	{
		ft_strlcpy(str, s + k + 1, i + 1);
		s += 1;
	}
	else
		ft_strlcpy(str, s + k, i + 1);
	return (str);
}

char			**ft_split(char const *s, char c, t_shell *f)
{
	int		rows;
	int		i;
	int		j;
	char	**tab;

	j = 0;
	if (!s)
		return (NULL);
	rows = ft_rows(s, c);
	i = -1;
	if (!(tab = malloc(sizeof(char *) * (rows + 1))))
		return (NULL);
	while (++i < rows)
	{
		while (s[j] == c)
			j++;
		if (!(tab[i] = ft_str_malloc(s, c, j, f)))
		{
			while (i > 0)
				free(tab[i--]);
			free(tab);
			return (NULL);
		}
		j += ft_strlen(tab[i]);
		if (f->flag == 1)
		{
			j += 2;
			f->flag = 0;
		}
	}
	tab[i] = 0;
	return (tab);
}
