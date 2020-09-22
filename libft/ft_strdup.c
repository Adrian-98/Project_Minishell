/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 21:18:32 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/09/22 19:48:18 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	p = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	if (p == NULL)
		return (0);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strndup(const char *src, size_t chars)
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
