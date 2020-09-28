/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:26:11 by amunoz-p          #+#    #+#             */
/*   Updated: 2019/11/27 14:18:24 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

void	ft_print_array_left_align(char *src, t_struct *f)
{
	int size;

	if (!src)
		src = "(null)";
	size = ft_strlen(src);
	if (f->precision_true && size > 0 && size > f->precision)
		size = f->precision;
	f->len += write(f->fd, src, size);
	while (f->width > size)
	{
		f->len += write(f->fd, " ", 1);
		f->width--;
	}
}

void	ft_print_array_right_align(char *src, t_struct *f)
{
	int size;

	if (!src)
		src = "(null)";
	size = ft_strlen(src);
	if (f->precision_true && size > 0 && f->precision < size)
		size = f->precision;
	while (f->width > size)
	{
		if (f->zero)
			f->len += write(f->fd, "0", 1);
		else
			f->len += write(f->fd, " ", 1);
		f->width--;
	}
	f->len += write(f->fd, src, size);
}

void	ft_print_array(va_list argptr, t_struct *f)
{
	char *src;

	src = va_arg(argptr, char *);
	if (f->align)
	{
		ft_print_array_left_align(src, f);
	}
	else
	{
		ft_print_array_right_align(src, f);
	}
}
