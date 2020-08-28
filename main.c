/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:10:01 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/08/28 19:49:09 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"


static	t_shell		*ft_create_struct(t_shell *f)
{
	if (!(f = malloc(sizeof(t_shell))))
		return 0;
	return(f);
}

void	display_msg(void)
{
	ft_putstr(" \033[31m♛");
	ft_putstr("\033[0m\033[34m☻\033[0m\033[35m♛\033[0m➣% ");
}
 
void	ft_pwd(t_shell *f)
{
	f->path = getcwd(f->path, 4096);
	printf("esto es path%s\n", f->path);
}

int main(int argc, char **argv, char **env)
{
	t_shell *f;
	
	f = NULL;
	f = ft_create_struct(f);
	
	while (1)
	{
		display_msg();			
		get_next_line(0, &f->line);
		
		if (ft_strncmp("exit", f->line, ft_strlen(f->line)) == 0)
			return(0);
		else if (ft_strncmp("pwd", f->line, ft_strlen(f->line)) == 0)
			ft_pwd(f);
		else
			printf("zsh: command not found: %s\n", f->line);
		free(f->line);
	}
	return 0;
}
