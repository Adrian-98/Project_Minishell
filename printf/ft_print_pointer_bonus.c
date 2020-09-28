/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:49:37 by amunoz-p          #+#    #+#             */
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

static void		ft_print_right_point(t_struct *f, unsigned long nbr)
{
	int		nbrsize;

	nbrsize = ft_count_digitspoint(nbr, 1);
	ft_add_rigth_align(ft_count_digitspoint(nbr, 1), f);
	f->len += write(f->fd, "0x", 2);
	while (nbrsize++ < (f->precision + 2))
		f->len += write(f->fd, "0", 1);
	ft_pointer(nbr, f, 1);
}

static void		ft_print_left_point(t_struct *f, unsigned long nbr)
{
	int nbrsize;

	nbrsize = ft_count_digitspoint(nbr, 1);
	f->len += write(f->fd, "0x", 2);
	while (nbrsize++ < f->precision + 2)
		f->len += write(f->fd, "0", 1);
	ft_pointer(nbr, f, 1);
	ft_add_left_align(ft_count_digitspoint(nbr, 1), f);
}

void			ft_print_pointer(char type, va_list argptr, t_struct *f)
{
	unsigned long nbr;

	nbr = va_arg(argptr, unsigned long);
	if (type == 'p')
	{
		if (nbr == '\0' && f->precision == 0 && f->precision_true == 1)
		{
			ft_print_pointer_null(f);
		}
		else if (f->align)
			ft_print_left_point(f, nbr);
		else
			ft_print_right_point(f, nbr);
	}
}
