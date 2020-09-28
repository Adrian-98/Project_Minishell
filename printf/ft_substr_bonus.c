/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:16:16 by amunoz-p          #+#    #+#             */
/*   Updated: 2019/11/27 17:16:32 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

char			*ft_substr(char *s, int start, int len)
{
	char				*puntero;
	int					i;

	if (s == NULL)
		return (NULL);
	if (!(puntero = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		puntero[i] = 0;
		i++;
	}
	if (i > start)
	{
		i = 0;
		while (len-- > 0)
		{
			puntero[i] = s[start];
			i++;
			start++;
		}
	}
	puntero[i] = '\0';
	return (puntero);
}
