/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 18:47:21 by glopez-a          #+#    #+#             */
/*   Updated: 2020/09/15 20:16:27 by amunoz-p         ###   ########.fr       */
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

char			**ft_split_cmd(char const *s, char *c, t_shell *f)
{
	int		rows;
	int		i;
	char	**tab = NULL;
	pid_t	pid;
	int		j;
	int		fd[2];
	char	info[100];
	(void)f;

	printf("valor de info ANTES de llenarlo = %s\n", info);
	pipe(fd);
	if (pipe(fd) == -1){
		printf("error with fd");
		return 0;
	}
	pid = fork();
	j = 0;
	if (!s)
		return (NULL);
	if (pid > 0)
	{
		close(fd[1]);
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
		read(fd[0], info, 100);
		close(fd[0]);
		printf("VVVVVVVVVVVvalor de info= %s\n", info);
		return (tab);
	}
	else if (pid == 0)
	{
		i = 0;
		close(fd[0]);
		while (s[i] != 0)
		{
			printf("valor de s[i]=%c\n", s[i]);
			if (s[i] == c[0] || s[i] == c[1])
			{
				info[j] = s[i];
				j++;
			}
			i++;
		}
		info[j] = 0;
		printf("valor de INFO=%s\n",info);
		write(fd[1], info, j + 1);
		printf("tu puta madre\n");
		close(fd[1]);
		exit(0);
	}
	else
		printf("error\n");
	return (tab);
}
