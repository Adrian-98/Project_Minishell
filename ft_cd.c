/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:57:14 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/09/21 18:45:07 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_cd(t_shell *f)
{
	int i;

	i = 0;
	while (f->arguments[i])
		i++;
	if (i >= 3)
		ft_too_many(f);
	else if ((f->arguments[1]) == 0)
	{
		if (chdir("/Users/amunoz-p/") != 0)
			printf("%s\n", strerror(errno));
	}
	else if (chdir(f->arguments[1]) != 0)
		printf("%s\n", strerror(errno));
}
