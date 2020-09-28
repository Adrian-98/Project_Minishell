/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:53:53 by amunoz-p          #+#    #+#             */
/*   Updated: 2019/12/10 17:59:01 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

static void	ft_add_left_align(int nbrsize, t_struct *f, int n)
{
	(void)n;
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

static void	ft_add_rigth_align(int nbrsize, t_struct *f, int n)
{
	if (f->plus == 1 && n == 0)
		f->len += write(f->fd, "+", 1);
	else if (f->space == 1 && f->width == 0)
		f->len += write(f->fd, " ", 1);
	if (nbrsize < f->precision)
	{
		if (n == 1)
			f->width--;
		while (f->width > f->precision)
		{
			ft_while(f);
			f->width--;
		}
	}
	else
	{
		if (n == 1 && f->zero == 1)
			f->len += write(1, "-", 1);
		while (f->width > nbrsize)
		{
			ft_while(f);
			f->width--;
		}
	}
}

static void	ft_print_decimal_left_align(int nbr, t_struct *f)
{
	int		nbrsize;
	int		n;
	char	*c;

	nbrsize = (nbr == 0 && f->precision == 0
	&& f->precision_true == 1) ? 0 : ft_count_digits(nbr);
	n = (nbr < 0) ? 1 : 0;
	nbr = (nbr < 0) ? -nbr : nbr;
	if (n == 1 && nbr != -2147483648)
	{
		f->len += write(f->fd, "-", 1);
		nbrsize--;
		f->width--;
	}
	while (nbrsize < f->precision)
	{
		f->len += write(f->fd, "0", 1);
		nbrsize++;
	}
	c = ft_itoa(nbr);
	if (nbr == 0 && f->precision == 0 && f->precision_true == 1)
		c = ft_set_zero(c, f);
	f->len += write(f->fd, c, ft_count_digits(nbr));
	ft_add_left_align(nbrsize, f, n);
}

static void	ft_print_decimal_rigth_align(int nbr, t_struct *f)
{
	int		n;
	int		nbrsize;
	char	*c;

	nbrsize = (nbr == 0 && f->precision == 0 && f->precision_true == 1)
	? 0 : ft_count_digits(nbr);
	n = (nbr < 0) ? 1 : 0;
	nbr = (nbr < 0) ? -nbr : nbr;
	ft_add_rigth_align(nbrsize, f, n);
	if (n == 1 && f->zero == 0 && nbr != -2147483648)
	{
		f->len += write(f->fd, "-", 1);
		nbrsize--;
	}
	while (nbrsize < f->precision)
	{
		f->len += write(f->fd, "0", 1);
		nbrsize++;
	}
	c = ft_itoa(nbr);
	if (nbr == 0 && f->precision == 0 && f->precision_true == 1)
		write(f->fd, NULL, 1);
	else
		f->len += write(f->fd, c, ft_count_digits(nbr));
}

void		ft_print_nb(char type, va_list argptr, t_struct *f)
{
	int nbr;

	if (type == 'i' || type == 'd')
	{
		nbr = va_arg(argptr, int);
		if (f->align)
			ft_print_decimal_left_align(nbr, f);
		else
			ft_print_decimal_rigth_align(nbr, f);
	}
}
