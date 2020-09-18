/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:55:43 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/09/18 17:33:17 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			i;
	unsigned char	*pajar;
	size_t			j;

	pajar = (unsigned char*)haystack;
	i = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (pajar[i] != '\0' && i < len)
	{
		if (pajar[i] == '"') //este liena es solo para que funcione el  echo
			return (NULL);
		j = 0;
		if (pajar[i] == needle[j])
		{
			while (pajar[i + j] == needle[j] && i + j < len)
			{
				j++;
				if (needle[j] == '\0')
					return (&((char*)haystack)[i]);
			}
		}
		i++;
	}
	return (NULL);
}
