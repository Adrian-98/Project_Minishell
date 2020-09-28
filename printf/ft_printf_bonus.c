/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:22:46 by amunoz-p          #+#    #+#             */
/*   Updated: 2019/12/10 17:28:04 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

static	t_struct		*ft_creatstruct(t_struct *f)
{
	if (!(f = malloc(sizeof(t_struct))))
		return (0);
	f->i = 0;
	f->len = 0;
	f->fd = 1;
	f->align = 0;
	f->zero = 0;
	f->width = 0;
	f->precision = 0;
	f->precision_true = 0;
	f->plus = 0;
	f->space = 0;
	f->has = 0;
	f->l = 0;
	f->ll = 0;
	f->h = 0;
	f->hh = 0;
	return (f);
}

int						ft_printf(const char *src, ...)
{
	int			len;
	va_list		argptr;
	t_struct	*f;

	f = NULL;
	f = ft_creatstruct(f);
	if (f == NULL)
		return (-1);
	va_start(argptr, src);
	if (ft_strchr(src, '%') == NULL)
		f->len = write(f->fd, src, ft_strlen(src));
	else
		ft_read_special(src, argptr, f);
	len = f->len;
	free(f);
	va_end(argptr);
	return (len);
}
