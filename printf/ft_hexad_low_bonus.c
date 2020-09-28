/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexad_low_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:43:09 by amunoz-p          #+#    #+#             */
/*   Updated: 2019/11/27 14:18:24 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

void		ft_hexad_low(unsigned int c, t_struct *f)
{
	if (c != 0)
	{
		ft_hexad_low(c / 16, f);
		if (c % 16 >= 10)
			ft_putchar('a' + c % 16 % 10, f);
		else
			ft_putchar('0' + c % 16, f);
	}
}
