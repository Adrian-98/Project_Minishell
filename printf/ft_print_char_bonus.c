/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:12:53 by amunoz-p          #+#    #+#             */
/*   Updated: 2019/11/27 14:18:24 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

void		ft_print_char(char type, va_list argptr, t_struct *f)
{
	char c[2];

	c[0] = type == '%' ? '%' : (char)va_arg(argptr, int);
	c[1] = '\0';
	if (c[0] == '\0')
	{
		ft_print_null_case_char(c, f);
	}
	else if (f->align)
	{
		ft_print_array_left_align(c, f);
	}
	else
	{
		ft_print_array_right_align(c, f);
	}
}
