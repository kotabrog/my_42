/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 12:28:09 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/07/24 11:39:49 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <wchar.h>
# define BUF 2050

typedef struct	s_flag
{
	int	flag[5];
	int	field;
	int	acc;
	int	modifier;
	int	specifier;
	int	putnum;
	int	putlen;
	int	copy_acc;
}				t_flag;

typedef struct	s_string
{
	char	*s;
	wchar_t	*ws;
	char	*copy_s;
	wchar_t	*copy_ws;
	int		flag;
}				t_string;

typedef struct	s_double
{
	double				d;
	int					sign;
	int					exp;
	unsigned long long	val;
	int					num[BUF];
	int					h_p;
	int					l_p;
	int					n_zero;
}				t_double;

char			*ft_strchr(const char *s, int c);
int				ft_strchr_n(const char *s, int c);
char			*ft_strchr_ex(const char *s, int c, ssize_t *len, int *flag);
int				ft_isdigit(int c);
void			ft_putchar_fd(char c, int fd);
void			ft_putchar_re_fd(char c, int fd, int n);
int				ft_putchar_uni(wint_t c, int fd);
void			ft_putnbr_fd(long long n, int fd);
void			ft_putnbr_fd_u(unsigned long long n, int fd, int mode);
int				ft_get_ndigits(long long n);
int				ft_get_ndigits_u(unsigned long long n, int mode);
unsigned int	ft_abs(int n);
int				ft_divrem(int n, int q, int mode);
int				ft_printf(const char *fmt, ...);
int				ft_dec_print(const char **start, const char **fmt, \
							va_list *ap, t_flag *bp);
void			ft_double_print(va_list *ap, t_flag *bp);
void			ft_double_arr(int arr[BUF], int *n);
void			ft_halve_arr(int arr[BUF], int n);
void			ft_add_arr(int arr[BUF], int ans[BUF], int n);
void			ft_add_arr2(int arr[BUF], int ans[BUF], int *n, int start);
void			ft_reset_arr(int *arr, int n);
void			ft_double_putlen(t_flag *bp, t_double *d, int *flag);
int				ft_is_inf_nan(double d);
void			ft_put_plus_minus(t_flag *bp, long long num_l);
void			ft_string_print(va_list *ap, t_flag *bp);
void			ft_int_print(va_list *ap, t_flag *bp);
void			ft_unsigned_print(va_list *ap, t_flag *bp);
void			ft_pointer_print(va_list *ap, t_flag *bp);
void			ft_char_print(va_list *ap, t_flag *bp);

#endif
