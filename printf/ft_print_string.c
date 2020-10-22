/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 10:54:23 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/07/24 12:56:20 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_null_print(t_flag *bp, t_string *s, int mode)
{
	s->flag = 0;
	if (!mode)
	{
		s->s = "(null)";
		bp->putlen = 6;
		if (bp->putlen > bp->acc)
			bp->putlen = bp->acc;
	}
	else if (bp->specifier >= 5 && bp->specifier <= 7)
	{
		if (bp->modifier == 2)
			s->s = "nan";
		else if (bp->modifier == 1)
			s->s = "inf";
		bp->putlen = 3 + (bp->modifier == 1 && \
				(bp->flag[3] || bp->flag[4] || bp->copy_acc));
		bp->acc = INT_MAX;
	}
	return (0);
}

int		ft_char_count(t_flag *bp, wint_t c)
{
	int n;

	if (bp->modifier != 1)
		n = 1;
	else if (c <= 0x7F)
		n = 1;
	else if (c <= 0x7FF)
		n = 2;
	else if (c <= 0xFFFF)
		n = 3;
	else
		n = 4;
	return (n);
}

int		ft_set_t_string(va_list *ap, t_flag *bp, t_string *s)
{
	int n;

	n = 0;
	if (ap == NULL)
		return (ft_null_print(bp, s, 1));
	if (bp->modifier == 1)
	{
		if ((s->ws = va_arg(*ap, wchar_t *)) == NULL)
			return (ft_null_print(bp, s, 0));
		s->flag = 1;
		s->copy_ws = s->ws;
		while ((bp->putlen += n) < bp->acc && *(s->copy_ws))
			n = ft_char_count(bp, *(s->copy_ws++));
	}
	else
	{
		if ((s->s = va_arg(*ap, char *)) == NULL)
			return (ft_null_print(bp, s, 0));
		s->flag = 0;
		s->copy_s = s->s;
		while (n < bp->acc && *(s->copy_s++))
			n++;
		bp->putlen = n;
	}
	return (n);
}

void	ft_string_print(va_list *ap, t_flag *bp)
{
	t_string	s;
	int			n;

	if (bp->acc < 0)
		bp->acc = INT_MAX;
	n = ft_set_t_string(ap, bp, &s);
	if (bp->putlen > bp->acc)
		bp->putlen -= n;
	bp->field = (bp->field <= bp->putlen ? 0 : bp->field - bp->putlen);
	if (!bp->flag[2])
		ft_putchar_re_fd((!bp->flag[1] || (bp->specifier >= 5 \
			&& bp->specifier <= 7)) ? ' ' : '0', 1, bp->field);
	n = bp->putlen - (bp->specifier >= 5 && bp->specifier <= 7 &&\
					(bp->flag[3] || bp->flag[4] || bp->copy_acc) &&\
					bp->modifier == 1);
	if (bp->specifier >= 5 && bp->specifier <= 7 && bp->modifier == 1)
		ft_put_plus_minus(bp, bp->copy_acc);
	if (s.flag)
		while (n > 0)
			n -= ft_putchar_uni(*(s.ws++), 1);
	else
		write(1, s.s, n);
	if (bp->flag[2])
		ft_putchar_re_fd(' ', 1, bp->field);
}

void	ft_char_print(va_list *ap, t_flag *bp)
{
	wint_t c;

	if (bp->modifier == 1)
		c = va_arg(*ap, wint_t);
	else
		c = (char)va_arg(*ap, int);
	bp->putlen = ft_char_count(bp, c);
	bp->field = (bp->field <= bp->putlen ? 0 : bp->field - bp->putlen);
	if (!bp->flag[2])
		ft_putchar_re_fd(' ', 1, bp->field);
	ft_putchar_uni(c, 1);
	if (bp->flag[2])
		ft_putchar_re_fd(' ', 1, bp->field);
}
