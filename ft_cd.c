/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-a <glopez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:57:14 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/10/15 19:15:08 by glopez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_cd(t_shell *f)
{
	int		i;
	char	**tmp;
	char	*str;

	i = 0;
	while (f->arg[i])
		i++;
	if (i >= 3)
		ft_too_many(f);
	else if ((f->arg[1]) == 0)
	{
		if (chdir(f->home) != 0)
			ft_printf("%s\n", strerror(errno));
		f->pwd = getcwd(f->pwd, 4096);
		str = ft_strjoin("PWD=", f->pwd);
		ft_export(f, str, tmp);
	}
	else
	{
		if (chdir(f->arg[1]) != 0)
			ft_printf("cd: %s: %s\n", strerror(errno), f->arg[1]);
		f->pwd = getcwd(f->pwd, 4096);
		str = ft_strjoin("PWD=", f->pwd);
		ft_export(f, str, tmp);
	}
	free(str);
	return (0);
}

void		ft_clear(t_shell *f)
{
	char	**str;
	pid_t	id;

	str = malloc(sizeof(char *) * 2);
	str[0] = "clear";
	str[1] = 0;
	id = fork();
	if (id == 0)
		execve("/usr/bin/clear", str, f->envv);
	wait(0);
	free(str);
}
