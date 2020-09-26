/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:57:14 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/09/26 13:52:16 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_cd(t_shell *f)
{
	int i;
	char	**tmp;



	i = 0;
	while (f->arguments[i])
		i++;
	if (i >= 3)
		ft_too_many(f);
	else if ((f->arguments[1]) == 0)
	{
		ft_printf("entra aqui\n");
		if (chdir("/Users/amunoz-p/") != 0)
			ft_printf("%s\n", strerror(errno));
		f->pwd = getcwd(f->pwd, 4096);
		ft_export(f, ft_strjoin("PWD=", f->pwd), tmp);
		
	}
	else 
	{
		if (chdir(f->arguments[1]) != 0)	
			ft_printf("cd: %s: %s\n", strerror(errno), f->arguments[1]);
		f->pwd = getcwd(f->pwd, 4096);
		ft_export(f, ft_strjoin("PWD=", f->pwd), tmp);
	}
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
}
