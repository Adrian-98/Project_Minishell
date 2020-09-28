/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:19:57 by amunoz-p          #+#    #+#             */
/*   Updated: 2019/11/27 14:18:24 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

void		ft_pointer(unsigned long nbr, t_struct *f, int start)
{
	if (start && nbr == '\0')
		f->len += write(f->fd, "0", 1);
	if (nbr != 0)
	{
		ft_pointer(nbr / 16, f, 0);
		if (nbr % 16 >= 10)
			ft_putchar('a' + nbr % 16 % 10, f);
		else
			ft_putchar('0' + nbr % 16, f);
	}
}
