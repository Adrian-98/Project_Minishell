/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or_case_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:48:13 by amunoz-p          #+#    #+#             */
/*   Updated: 2019/12/02 11:59:03 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

void		ft_or_case(const char *src, va_list argptr, t_struct *f)
{
	if (src[f->i] == 'c')
		ft_print_char(src[f->i], argptr, f);
	else if (src[f->i] == 's')
		ft_print_array(argptr, f);
	else if (src[f->i] == 'd' || src[f->i] == 'i')
		ft_print_nb(src[f->i], argptr, f);
	else if (src[f->i] == 'u')
		ft_print_unsigned(src[f->i], argptr, f);
	else if (src[f->i] == 'x' || src[f->i] == 'X')
		ft_print_hexa(src[f->i], argptr, f);
	else if (src[f->i] == 'p')
		ft_print_pointer(src[f->i], argptr, f);
	else if (src[f->i] == '%')
		ft_print_char('%', argptr, f);
	else if (src[f->i] == 'n')
		ft_print_n(&src[f->i], argptr, f);
}
