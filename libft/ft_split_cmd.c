/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 18:47:21 by glopez-a          #+#    #+#             */
/*   Updated: 2020/10/12 18:33:45 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_pipe_counter(t_shell *f)
{
	int i;

	f->p = 0;
	i = 0;
	while (f->info[i])
	{
		if (f->info[i] == '|')
			f->p++;
		i++;
	}
}

static void		ft_info(const char *s, char *c, t_shell *f)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		if (s[i] == c[0] || s[i] == c[1])
			j++;
		i++;
	}
	i = 0;
	f->info = malloc(sizeof(j + 1));
	j = 0;
	while (s[i] != 0)
	{
		if (s[i] == c[0] || s[i] == c[1])
		{
			f->info[j] = s[i];
			j++;
		}
		i++;
	}
	f->info[j] = 0;
	ft_pipe_counter(f);
}

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
			while (s[i] && (s[i] == c[0] || s[i] == c[1]))
				i++;
		else
			i++;
	}
	return (rows);
}

static	char	*ft_str_malloc(char const *s, char *c, t_shell *f)
{
	int		i;
	char	*str;

	(void)f;
	i = 0;
	while (s[i] && s[i] != c[0] && s[i] != c[1])
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ft_strlcpy(str, s, i + 1);
	return (str);
}

char			**ft_split_cmd(char const *s, char *c, t_shell *f)
{
	int		rows;
	int		i;
	char	**tab;

	ft_info(s, c, f);
	rows = ft_rows(s, c);
	i = -1;
	if (!(tab = malloc(sizeof(char *) * (rows + 1))))
		return (NULL);
	while (++i < rows)
	{
		while (*s == c[0] || *s == c[1])
			s++;
		if (!(tab[i] = ft_str_malloc(s, c, f)))
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
