/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:10:01 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/08/10 20:24:01 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int main(int argc, char **argv, char **env)
{
	char *line;

	while (1)
	{
		get_next_line(0, &line);
		if (ft_memcmp("exit", line, ft_strlen("exit")) == 0)
			return(0);
		//printf("hola\n");
		printf("%s\n", line);
		
	}
	return 0;
}
