/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_null_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:42:24 by amunoz-p          #+#    #+#             */
/*   Updated: 2019/11/27 14:18:24 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

static void		ft_add_rigth_align(int nbrsize, t_struct *f)
{
	if (nbrsize < f->precision)
	{
		while (f->width > f->precision)
		{
			if (f->zero && f->precision_true == 0)
				f->len += write(f->fd, "0", 1);
			else
				f->len += write(f->fd, " ", 1);
			f->width--;
		}
	}
	else
	{
		while (f->width > nbrsize)
		{
			if (f->zero && f->precision_true == 0)
				f->len += write(f->fd, "0", 1);
			else
				f->len += write(f->fd, " ", 1);
			f->width--;
		}
	}
}

static void		ft_add_left_align(int nbrsize, t_struct *f)
{
	if (nbrsize < f->precision)
	{
		while (f->width > f->precision)
		{
			f->len += write(f->fd, " ", 1);
			f->width--;
		}
	}
	else
	{
		while (f->width > nbrsize)
		{
			f->len += write(f->fd, " ", 1);
			f->width--;
		}
	}
}

void			ft_print_hexa_null(t_struct *f, int nbr)
{
	int size;

	size = ft_count_digitshexa(nbr);
	if (f->align)
	{
		f->len += write(1, "0", 1);
		ft_add_left_align(1, f);
	}
	else
	{
		ft_add_rigth_align(1, f);
		f->len += write(1, "0", 1);
	}
}
