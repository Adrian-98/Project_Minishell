/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 12:23:13 by amaza-va          #+#    #+#             */
/*   Updated: 2019/11/13 21:18:37 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	set_chars(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static	int	str_size(char const *s1, char const *set)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1);
	while (set_chars(s1[len - i - 1], set))
		i++;
	return (len - i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	size = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (set_chars(s1[i], set))
		i++;
	if (i == (int)ft_strlen(s1))
		return (ft_strdup(""));
	size = str_size(s1 + i, set) + 1;
	if (!(str = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_strlcpy(str, s1 + i, size);
	return (str);
}
