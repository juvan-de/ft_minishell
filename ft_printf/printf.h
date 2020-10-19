/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 10:50:06 by avan-ber       #+#    #+#                */
/*   Updated: 2020/01/06 14:37:45 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stddef.h>
# include <wchar.h>
# include <stdarg.h>
# include <unistd.h>

typedef	struct	s_flags
{
	int			dash;
	int			zero;
	int			star;
	int			precision;
	int			prenumber;
	int			width;
	int			plus;
	int			space;
	int			hash;
	int			apostrophe;
	int			length;
}				t_flags;

typedef struct	s_float
{
	long long	nb_before;
	int			nb_before_length;
	long long	nb_after;
	int			nb_after_length;
	int			length;
	int			neg;
	int			power;
	int			nb_zero_sign;
}				t_float;

typedef struct	s_wcharinfo
{
	int			amount;
	int			bytes;
}				t_wcharinfo;

/*
** printf
*/
int				ft_printf(const char *str, ...);
void			get_format(t_flags *flags, char **str, va_list ap);

/*
** print functions
*/
int				print_char(t_flags flags, char c);
int				print_char_w(t_flags flags, wint_t c);
int				print_str(t_flags flags, char *str);
int				print_str_w(t_flags flags, wchar_t *str);
int				print_int(t_flags flags, long long nb);
int				print_unsigned_int(t_flags flags, unsigned long long nb);
int				print_octal(t_flags flags, unsigned long long nb);
int				print_hexa_low(t_flags flags, unsigned long long nb);
int				print_hexa_up(t_flags flags, unsigned long long nb);
int				print_pointer(t_flags flags, void *adress);
int				print_float(t_flags flags, double nb, int cap, int prezero);
int				print_g(t_flags flags, double nb, int cap);
int				print_e(t_flags flags, double nb, int cap, int prezero);

/*
** get size functions
*/
int				get_size_char(t_flags flags, va_list ap);
int				get_size_str(t_flags flags, va_list ap);
int				get_print_int(t_flags flags, va_list ap);
int				get_print_unsigned(t_flags flags, va_list ap);
int				get_print_octal(t_flags flags, va_list ap);
int				get_print_hexa_low(t_flags flags, va_list ap);
int				get_print_hexa_up(t_flags flags, va_list ap);
int				get_size_n(t_flags flags, va_list ap, int count);

/*
** printf utils
*/
int				ft_strlen_substr(const char **str, char c);
void			ft_putlstr_fd(char *str, int len, int fd);
size_t			ft_strlen(const char *s);
int				nbr_spacecounter_figure_base_u(unsigned long long nb, int base);
int				nbr_spacecounter_figure_base(long long nb, int base);

char			*ft_strchr(const char *s, int c);
void			ft_print_sign(t_flags flags, int neg);
void			setprecisionfloat(t_flags *flags);
void			setfloatinfozero(t_float *floatinfo);
long long		tentothepower(int power);

int				get_figure(long long nb);
int				get_print_char_hexa(t_flags flags, int nb, int len);
int				ft_wchar_len(wchar_t c);
void			put_float_after(t_flags flags, long long nb, int prezero);
void			print_c_l(wint_t c);
void			ft_putnbr_hexa_low_fd(unsigned long long nb, int len, int fd);

void			setflagszero(t_flags *flags);
void			ft_putlspace(int len);
void			ft_putlzero(int len);

/*
**	printf utils float
*/
int				float_check_edge(double nb, int cap, t_flags flags);
void			put_float_after(t_flags flags, long long nb, int removezero);

/*
**	f and e extra non static functions
*/
void			get_floatinfo_f(t_flags flags, t_float *floatinfo, double nb,
																int removezero);
void			get_floatinfo_e(t_flags flags, t_float *floatinfo, double nb,
																int removezero);

/*
**	n extra non static functions
*/
void			fill_n(t_flags flags, long long int *n);
void			fill_n_int(va_list ap, int count);
void			fill_n_long(va_list ap, int count);
void			fill_n_longlong(va_list ap, int count);
void			fill_n_short(va_list ap, int count);
void			fill_n_shortshort(va_list ap, int count);

#endif
