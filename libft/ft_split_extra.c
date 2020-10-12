/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 19:27:57 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/10/12 19:39:45 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_extraaa(const char *s, char c, int i, int size)
{
	(void)c;
	if (s[i] == '"')
	{
		i++;
		while (s[i] != '"')
			i++;
		i++;
		size++;
	}
	return (size);
}

int		ft_str_malloc2(int k, char const *s, t_shell *f, char c)
{
	int i;

	i = 0;
	if (s[i + k] == '\'')
	{
		i++;
		while (s[i + k] != '\'')
			i++;
		f->flag1 = 1;
		i -= 1;
	}
	else if (s[i + k] == '"')
	{
		i++;
		while (s[i + k] != '"')
			i++;
		f->flag = 1;
		i -= 1;
	}
	else
		while (s[i + k] && s[i + k] != c && s[i + k] != '"' && s[i + k] != '\'')
			i++;
	return (i);
}
