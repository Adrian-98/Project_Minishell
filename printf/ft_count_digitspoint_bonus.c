/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digitspoint_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:04:15 by amunoz-p          #+#    #+#             */
/*   Updated: 2019/11/27 14:18:24 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

int		ft_count_digitspoint(unsigned long nb, int start)
{
	if (nb == 0 && start == 1)
		return (3);
	if (nb != 0)
		return (1 + ft_count_digitspoint(nb / 16, 0));
	else
		return (2);
}
