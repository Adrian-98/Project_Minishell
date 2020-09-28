/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 19:14:43 by amunoz-p          #+#    #+#             */
/*   Updated: 2019/11/27 14:18:24 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

static void	ft_add_left_align(int nbrsize, t_struct *f, int n)
{
	if (nbrsize < f->precision)
	{
		if (n == 1)
			f->width--;
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

static void	ft_add_rigth_align(int nbrsize, t_struct *f, int n)
{
	if (nbrsize < f->precision)
	{
		if (n == 1)
			f->width--;
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

static void	ft_print_unsigned_left(unsigned int nbr, t_struct *f)
{
	int		nbrsize;
	int		n;
	char	*c;

	nbrsize = ft_nb_digit_unsigned(nbr);
	n = (nbr < 0) ? 1 : 0;
	nbr = (nbr < 0) ? -nbr : nbr;
	if (n == 1)
	{
		f->len += write(f->fd, "-", 1);
		nbrsize--;
	}
	while (nbrsize++ < f->precision)
		f->len += write(f->fd, "0", 1);
	c = ft_itoa_unsigned(nbr);
	if (nbr == 0 && f->precision == 0 && f->precision_true == 1)
	{
		write(f->fd, NULL, 1);
		ft_add_left_align(0, f, n);
	}
	else
	{
		f->len += write(f->fd, c, ft_nb_digit_unsigned(nbr));
		ft_add_left_align(ft_nb_digit_unsigned(nbr), f, n);
	}
}

static void	ft_print_unsigned_right(unsigned int nbr, t_struct *f)
{
	int		n;
	int		nbrsize;
	char	*c;

	nbrsize = ft_nb_digit_unsigned(nbr);
	n = (nbr < 0) ? 1 : 0;
	nbr = (nbr < 0) ? -nbr : nbr;
	if (nbr == 0 && f->precision == 0 && f->precision_true == 1)
		nbrsize = 0;
	ft_add_rigth_align(nbrsize, f, n);
	if (n == 1)
	{
		f->len += write(f->fd, "-", 1);
		nbrsize--;
	}
	while (nbrsize++ < f->precision)
		f->len += write(f->fd, "0", 1);
	c = ft_itoa_unsigned(nbr);
	if (nbr == 0 && f->precision == 0 && f->precision_true == 1)
		write(f->fd, NULL, 1);
	else
		f->len += write(f->fd, c, ft_nb_digit_unsigned(nbr));
}

void		ft_print_unsigned(char type, va_list argptr, t_struct *f)
{
	unsigned int	nbr;

	if (type == 'u')
	{
		nbr = va_arg(argptr, unsigned int);
		if (f->align)
			ft_print_unsigned_left(nbr, f);
		else
			ft_print_unsigned_right(nbr, f);
	}
}
