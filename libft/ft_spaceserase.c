/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spaceserase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 20:51:16 by adrian            #+#    #+#             */
/*   Updated: 2020/10/19 19:39:49 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_spaceserase(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[j] == ' ')
		j++;
	while (str[i])
		i++;
	new_str = malloc(sizeof(char) * (i - j + 1));
	i = 0;
	while (str[j] && str[j] != ' ')
	{
		new_str[i] = str[j];
		i++;
		j++;
	}
	new_str[i] = 0;
	return (new_str);
}
