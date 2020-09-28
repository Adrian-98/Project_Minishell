/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_special_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:59:02 by amunoz-p          #+#    #+#             */
/*   Updated: 2019/12/10 18:08:14 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

static void		ft_precision(const char *src, va_list argptr, t_struct *f)
{
	if (src[f->i] == '.')
	{
		f->i++;
		f->precision_true = 1;
		f->zero = 0;
		if (src[f->i] == '*')
		{
			f->precision = va_arg(argptr, int);
			while (src[f->i] == '*')
				f->i++;
		}
		else if (ft_isdigit(src[f->i]))
		{
			f->precision = ft_atoi(&src[f->i]);
			while (ft_isdigit(src[f->i]))
				f->i++;
		}
		if (f->precision < 0)
		{
			f->precision_true = 0;
			f->precision = 0;
		}
	}
}

static void		ft_width(const char *src, va_list argptr, t_struct *f)
{
	if (src[f->i] == '*')
	{
		f->width = va_arg(argptr, int);
		f->align = (f->width < 0) ? 1 : f->align;
		f->zero = (f->width < 0) ? 0 : f->zero;
		f->width = (f->width < 0) ? -f->width : f->width;
		while (src[f->i] == '*')
			f->i++;
	}
	else if (ft_isdigit(src[f->i]))
	{
		f->width = ft_atoi(&src[f->i]);
		while (ft_isdigit(src[f->i]))
			f->i++;
	}
}

static void		ft_flags(const char *src, t_struct *f)
{
	while (ft_strchr("0-#+ ", src[f->i]))
	{
		if (src[f->i] == '-')
			f->align = 1;
		else if (src[f->i] == '0')
			f->zero = 1;
		else if (src[f->i] == ' ')
			f->space = 1;
		else if (src[f->i] == '+')
		{
			f->plus = 1;
			f->zero = 0;
			f->align = 0;
			f->space = 0;
		}
		else if (src[f->i] == '#')
		{
			f->has = 1;
			f->align = 0;
		}
		f->i++;
	}
	if (f->align == 1)
		f->zero = 0;
}

static void		ft_org_flags(const char *src, va_list argptr, t_struct *f)
{
	ft_flags(src, f);
	ft_width(src, argptr, f);
	ft_precision(src, argptr, f);
	ft_cast(src, f);
}

void			ft_read_special(const char *src, va_list argptr, t_struct *f)
{
	char		*str;

	str = "cspdiuxXn%";
	while (src[f->i] != '\0')
	{
		if (src[f->i] == '%')
		{
			f->i++;
			if (ft_strchr("0-.*123456789+ #lh", src[f->i]))
			{
				ft_org_flags(src, argptr, f);
			}
			if (ft_strchr(str, src[f->i]))
			{
				ft_or_case(src, argptr, f);
				ft_reset_struct(f);
			}
		}
		else
			f->len = f->len + write(f->fd, &src[f->i], 1);
		f->i++;
	}
}
