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

static	int	ft_rows(const char *s, char c, int *pointer)
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
		}
		if (s[i] != c)
		{
			size++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	*pointer = i - 1;
	printf("%d\n", size);
	return (size);
}


static	char	*ft_str_malloc(char const *s, char c)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (s[i] == '"')
	{
		i++;
		while (s[i] != '"')
			i++;
		j = 1;
		i--;
	}
	else
	{
		while (s[i] && s[i] != c)
			i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (j == 1)
		ft_strlcpy(str, ++s, i + 1);
	ft_strlcpy(str, s, i + 1);
	return (str);
}

char			**ft_split(char const *s, char c)
{
	int		rows;
	int		i;
	char	**tab;

	i = 0;
	if (!s)
		return (NULL);
	rows = ft_rows(s, c, &i);
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
