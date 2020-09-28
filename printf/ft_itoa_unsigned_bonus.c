/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:28:31 by amunoz-p          #+#    #+#             */
/*   Updated: 2019/11/27 14:18:24 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

int			ft_nb_digit_unsigned(unsigned int n)
{
	int size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char		*ft_itoa_unsigned(unsigned int n)
{
	int		aux;
	int		size;
	char	*out;

	aux = 0;
	size = ft_nb_digit_unsigned(n);
	if (!(out = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	out[size - 1] = '0';
	out[size] = '\0';
	if (n < 0)
		out[0] = '-';
	while (n != 0)
	{
		aux = n % 10;
		if (aux < 0)
			aux = -aux;
		out[size - 1] = '0' + aux;
		n = n / 10;
		size--;
	}
	return (out);
}
