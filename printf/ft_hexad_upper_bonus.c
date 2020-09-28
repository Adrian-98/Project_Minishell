/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexad_upper_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 09:58:06 by amunoz-p          #+#    #+#             */
/*   Updated: 2019/11/27 14:18:24 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_hexad_upper(unsigned int c, t_struct *f)
{
	if (c != 0)
	{
		ft_hexad_upper(c / 16, f);
		if (c % 16 >= 10)
			ft_putchar('A' + (c % 16 % 10), f);
		else
			ft_putchar('0' + c % 16, f);
	}
}
