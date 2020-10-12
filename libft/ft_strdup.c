/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 21:18:32 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/10/12 18:31:41 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *src, size_t chars)
{
	char	*str;
	char	*strptr;

	if (!src)
		return (0);
	if (!(str = malloc((chars + 1) * sizeof(char))))
		return (0);
	strptr = str;
	while (*src && chars--)
		*(strptr++) = *(src++);
	*strptr = 0;
	return (str);
}

char		*ft_strjoin3(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s3;

	i = -1;
	j = -1;
	if (s1 && s2)
	{
		if (!(s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 3))))
			return (NULL);
		while (s1[++i])
		{
			s3[i] = s1[i];
		}
		s3[i++] = '/';
		while (s2[++j])
		{
			s3[i] = s2[j];
			i++;
		}
		s3[i] = '\0';
		return (s3);
	}
	return (0);
}
