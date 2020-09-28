/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 00:50:10 by jrameau           #+#    #+#             */
/*   Updated: 2020/09/28 19:50:44 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	proc_signal_handler(int signo)
{
	if (signo == SIGINT)
		ft_putstr("\n");
}


void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		display_msg();
	}
}

void signal1(int signo)
{
	if (signo == SIGQUIT)
		signal(SIGINT, signal1);
}

void signal2(int signo)
{
	if (signo == SIGQUIT)
	{
		ft_putstr("QUIT: 3\n");
	}
}