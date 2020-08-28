/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 19:20:28 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/08/28 20:01:42 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

typedef struct	shell_struct
{
	char	*line;
	char	*path;
}				t_shell;
// char			*ft_strjoin(char const *s1, char const *s2);
// char			*ft_strdup(const char *s1);
// char			*ft_strchr(char *s, char a);
// char			*ft_substr(char *s, int start, int len);
void		display_msg(t_shell *f);
void		ft_pwd(t_shell *f);

#endif