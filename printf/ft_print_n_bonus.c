/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_n_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:03:48 by amunoz-p          #+#    #+#             */
/*   Updated: 2019/12/10 17:50:33 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

void		ft_print_n(const char *src, va_list argptr, t_struct *f)
{
	int *s;

	(void)src;
	s = va_arg(argptr, int *);
	s = &f->len;
}
