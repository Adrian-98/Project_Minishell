/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digitshexa_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 19:36:18 by amunoz-p          #+#    #+#             */
/*   Updated: 2019/11/27 14:18:24 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

int		ft_count_digitshexa(int nb)
{
	int i;

	i = 0;
	if (nb < 0)
		return (8);
	while (nb != 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}
