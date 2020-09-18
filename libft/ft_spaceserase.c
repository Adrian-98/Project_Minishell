/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spaceserase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 20:51:16 by adrian            #+#    #+#             */
/*   Updated: 2020/09/18 15:39:09 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_spaceserase(char *str)
{
	char	*new_str;
	int		start;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n'))
		i++;
	start = i;
	i = ft_strlen(str) - 1;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n'))
		i--;
	return ((new_str = (ft_strsub(str, start, i - start + 1))));
}
