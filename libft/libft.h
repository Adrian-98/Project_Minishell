/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:44:40 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/10/13 16:26:15 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct	s_structed
{
	char	*line;
	char	**arg;
	char	*pwd;
	char	**path;
	int		flag;
	int		flag1;
	int		flag2;
	int		p;
	int		i;
	int		fd1[2];
	int		fd2;
	int		ret;
	int		save[2];
	int		status;
	int		statuss;
	pid_t	pid;
	pid_t	pidt;
	int		quote;
	char	**envv;
	char	**process;
	char	*info;
	char	*erno;
	char	*home;
	char	**pipes;
	char	**redi;

	int		z;
	int		x;
	int		c;

	int		a;
	int		b;
	int		k;
}				t_shell;

int				ft_str_malloc2(int k, char const *s, t_shell *f, char c);
int				ft_extraaa(const char *s, char c, int i, int size);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strndup(const char *src, size_t chars);
char			*ft_strjoin3(char const *s1, char const *s2);
char			*ft_strjoin2(char const *s1, char const *s2);
char			*ft_strjoin1(char const *s1, char const *s2);
char			**ft_split2(char const *s, char c);
char			**ft_split(char const *s, char c, t_shell *f);
char			**ft_split_cmd(char const *s, char *c, t_shell *f);
int				get_next_line(int fd, char **line);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, char a);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strnstr(const char *haystack, const char *needle,\
				size_t len);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void const *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),\
				void (*del)(void *));
void			ft_putstr(char *s);
char			*ft_spaceserase(char *str);
char			*ft_strsub(char *str, int start, size_t len);
char			*ft_strnew(size_t size);
size_t			ft_strlcpy1(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy2(char *dst, const char *src, size_t dstsize);

#endif
