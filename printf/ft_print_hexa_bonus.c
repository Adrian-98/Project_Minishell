/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 19:33:13 by amunoz-p          #+#    #+#             */
/*   Updated: 2019/12/10 14:33:19 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

static void		ft_add_rigth_align(int nbrsize, t_struct *f)
{
	if (nbrsize < f->precision)
	{
		while (f->width > f->precision)
		{
			if (f->zero)
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
			if (f->zero)
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
			if (f->zero && f->precision_true == 0)
				f->len += write(f->fd, " ", 1);
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
				f->len += write(f->fd, " ", 1);
			else
				f->len += write(f->fd, " ", 1);
			f->width--;
		}
	}
}

static void		ft_print_hexa_right(t_struct *f, unsigned int nbr, char type)
{
	int		nbrsize;

	nbrsize = ft_count_digitshexa(nbr);
	if (f->has == 1)
	{
		if (type == 'x')
			f->len += write(f->fd, "0x", 2);
		else if (type == 'X')
			f->len += write(f->fd, "0X", 2);
	}
	ft_add_rigth_align(ft_count_digitshexa(nbr), f);
	while (nbrsize++ < f->precision)
		f->len += write(f->fd, "0", 1);
	if (type == 'x')
		ft_hexad_low(nbr, f);
	else if (type == 'X')
		ft_hexad_upper(nbr, f);
}

static void		ft_print_hexa_left(t_struct *f, unsigned int nbr, char type)
{
	int nbrsize;

	nbrsize = ft_count_digitshexa(nbr);
	while (nbrsize++ < f->precision)
		f->len += write(f->fd, "0", 1);
	if (type == 'x')
		ft_hexad_low(nbr, f);
	else if (type == 'X')
		ft_hexad_upper(nbr, f);
	ft_add_left_align(ft_count_digitshexa(nbr), f);
}

void			ft_print_hexa(char type, va_list argptr, t_struct *f)
{
	int	nbr;

	nbr = va_arg(argptr, int);
	if (nbr == 0 && f->precision_true == 0)
		ft_print_hexa_null(f, nbr);
	else if (f->align)
		ft_print_hexa_left(f, nbr, type);
	else
		ft_print_hexa_right(f, nbr, type);
}
