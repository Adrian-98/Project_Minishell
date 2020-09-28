/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_null_case_char_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 13:46:35 by amunoz-p          #+#    #+#             */
/*   Updated: 2019/11/27 14:18:24 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

static void	ft_spaces_char(t_struct *f, int size)
{
	while (f->width > size)
	{
		if (f->zero)
			f->len += write(f->fd, "0", 1);
		else
			f->len += write(f->fd, " ", 1);
		f->width--;
	}
}

void		ft_print_null_case_char(char *c, t_struct *f)
{
	int	size;

	size = 1;
	f->len++;
	if (f->align == 1)
	{
		write(f->fd, c, 1);
		ft_spaces_char(f, size);
	}
	else
	{
		ft_spaces_char(f, size);
		write(f->fd, c, 1);
	}
}
