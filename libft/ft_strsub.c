/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 21:17:58 by adrian            #+#    #+#             */
/*   Updated: 2020/09/18 15:54:35 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char *str, int start, size_t len)
{
	char	*new;
	int		i;

	if (!str || !(new = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (len--)
		new[i++] = str[start++];
	return (new);
}
