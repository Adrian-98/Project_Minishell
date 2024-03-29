/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:20:44 by glopez-a          #+#    #+#             */
/*   Updated: 2020/10/12 18:25:38 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(char const *s, char a)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == a)
			return ((char *)(&s[i]));
		i++;
	}
	return (0);
}

char		*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i] != '\0')
		i++;
	s2 = (char *)malloc(sizeof(char) * i + 1);
	if (s2 == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s3;

	i = 0;
	j = -1;
	if (s1 && s2)
	{
		if (!(s3 = malloc(sizeof(char) *
		(ft_strlen(s1) + ft_strlen(s2) + 1))))
			return (NULL);
		while (s1[i])
		{
			s3[i] = s1[i];
			i++;
		}
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

char		*ft_strjoin1(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s3;

	i = 0;
	j = -1;
	if (s1 && s2)
	{
		if (!(s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2))))
			return (NULL);
		while (s1[i])
		{
			s3[i] = s1[i];
			i++;
		}
		s3[i++] = '\n';
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

char		*ft_strjoin2(char const *s1, char const *s2)
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
		s3[i++] = '\\';
		s3[i++] = 'n';
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
