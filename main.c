/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:10:01 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/08/27 19:57:09 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	display_msg(void)
{
	ft_putstr(" \033[31m♛");
	ft_putstr("\033[0m\033[34m☻\033[0m\033[35m♛\033[0m➣% ");
}
 
static void	ft_pwd(void)
{
	//printf("OOEFJWFOWHFOWF\n");
	char *id;
	char *print;
	print = getcwd(id, 50);
	printf("%s\n", print);
}

int main(int argc, char **argv, char **env)
{
	char *line;

	while (1)
	{
		display_msg();
		get_next_line(0, &line);
		if (ft_strncmp("exit", line, ft_strlen(line)) == 0)
			return(0);
		else if (ft_strncmp("pwd", line, ft_strlen(line)) == 0)
			ft_pwd();
		else
			printf("zsh: command not found: %s\n", line);
		
		//printf("$%s\n", line);
	}
	return 0;
}
