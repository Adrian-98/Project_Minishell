/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:49:38 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/10/12 19:24:26 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_BONUS_H
# define PRINTF_BONUS_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_struct
{
	int			i;
	int			len;
	int			fd;
	int			space;
	int			zero;
	int			width;
	int			align;
	int			precision;
	int			precision_true;
	int			plus;
	int			has;
	int			l;
	int			ll;
	int			h;
	int			hh;
}				t_struct;

void			ft_putnbr(int nb);
int				ft_valid_values(char c);
void			ft_pputstr(char *str, t_struct *node);
int				ft_printf(const char *src, ...);
int				ft_check_flags(char c);
void			ft_read_special(const char *s, va_list argptr, t_struct *f);
void			ft_print_especial_nb(int nb, t_struct *node);
void			ft_print_especial_char(char c, t_struct *node);
void			ft_print_especial_array(char *s, t_struct *node);
void			ft_putnbr_unsigned(unsigned int nb);
void			ft_print_especial_unsigned(unsigned	int nb, t_struct *node);
void			ft_hexad_upper(unsigned int c, t_struct *f);
void			ft_print_especial_hexadlow(unsigned int nb, t_struct *node);
void			ft_print_especial_hexadup(unsigned int nb, t_struct *node);
char			*ft_strchr(const char *s, char a);
size_t			ft_strlen(const char *s);
void			ft_reset_struct(t_struct *f);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
void			ft_or_case(const char *src, va_list argptr, t_struct *f);
void			ft_print_char(char s, va_list argptr, t_struct *f);
char			*ft_itoa(int n);
void			ft_print_nb(char type, va_list argptr, t_struct *f);
void			ft_print_char(char type, va_list argptr, t_struct *f);
void			ft_print_array(va_list argptr, t_struct *f);
int				ft_count_digits(int nb);
void			ft_print_unsigned(char type, va_list argptr, t_struct *f);
int				ft_count_digitshexa(int nb);
void			ft_hexad_low(unsigned int c, t_struct *f);
void			ft_print_hexa(char type, va_list argptr, t_struct *f);
void			ft_hexad_upper(unsigned int c, t_struct *f);
void			ft_putchar(char c, t_struct *f);
void			ft_print_pointer(char type, va_list argptr, t_struct *f);
int				ft_count_digitspoint(unsigned long nb, int start);
void			ft_pointer(unsigned long nbr, t_struct *f, int start);
void			ft_print_array_right_align(char *src, t_struct *f);
void			ft_print_array_left_align(char *src, t_struct *f);
void			ft_print_null_case_char(char *c, t_struct *f);
void			ft_print_pointer_null(t_struct *f);
void			ft_print_hexa_null(t_struct *f, int nbr);
char			*ft_itoa_unsigned(unsigned int n);
int				ft_nb_digit_unsigned(unsigned int n);
char			*ft_set_zero(char *c, t_struct *f);
void			ft_while(t_struct *f);
void			ft_plus(char *src, va_list argptr, t_struct *f);
char			*ft_psubstr(int *s, int start, int len);
void			ft_print_n(const char *src, va_list argptr, t_struct *f);
void			ft_cast(const char *src, t_struct *f);

#endif
