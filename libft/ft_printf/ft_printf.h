/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 11:57:49 by rmarracc          #+#    #+#             */
/*   Updated: 2018/11/29 22:48:01 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <sys/types.h>

typedef struct	s_arg
{
	int			arg;
	int			minus;
	int			plus;
	int			diese;
	int			zero;
	int			espace;
	int			width;
	int			precision;
	int			lenght;
}				t_arg;

void			ft_init_arg(t_arg *flag);
int				ft_printf(const char *fmt, ...);
void			ft_parse_options(char c, t_arg *flag);
int				ft_parse_precision(const char *fmt, t_arg *flag, int i);
int				ft_parse_lenght(const char *fmt, t_arg *flag, int i);
int				ft_is_arg1(char c);
int				ft_is_arg2(char c);
int				ft_skip_digit(const char *fmt, int i);
int				ft_process_arg(const char *fmt, t_arg *flag, int i);
int				ft_conversions(char c, t_arg *flag, va_list ap);
int				ft_parse_string(va_list ap, t_arg *flag, int ret, int pad);
int				ft_parse_char(va_list ap, t_arg *flag, int ret, int pad);
int				ft_parse_pointer(va_list ap, t_arg *flags, int ret, int pad);
int				ft_parse_percent(t_arg *flag, int ret, int pad, int spaces);
int				ft_parse_signed(va_list ap, t_arg *flag, int ret);
int				ft_parse_double(va_list ap, t_arg *flag, int ret);
int				ft_parse_unsigned(va_list ap, t_arg *flag, int ret);
int				ft_parse_octal(va_list ap, t_arg *flag, int ret);
int				ft_parse_hex(va_list ap, t_arg *flag, int ret, char c);
long double		ft_double_lenght(long double val, t_arg flag);
void			ft_flag_priority(t_arg *flag);
ssize_t			ft_signed_lenght(ssize_t val, t_arg flag);
size_t			ft_unsigned_lenght(size_t val, t_arg flag);
int				unsigned_size(size_t nb, char *base, int acc);
int				ft_uitoa_base(size_t nb, char *base, int acc);
int				signed_size(ssize_t nb, char *base, int acc);
int				ft_itoa_base(ssize_t nb, char *base, int acc);
int				ft_ftoa_base(long double nb, char *base, int acc, int p);
int				ft_max(int a, int b);
int				ft_res_hex_norme(char c, int ret, size_t nb);
int				ft_ip(int p);

#endif
