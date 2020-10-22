/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 10:52:07 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/07/24 11:53:30 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_get_putlen(t_flag *bp, long long num_l, unsigned long long num_ul)
{
	bp->flag[1] = bp->flag[1] && (bp->acc == -1);
	if (bp->specifier == 0 || bp->specifier == 1)
	{
		bp->putlen = ft_get_ndigits(num_l);
		bp->acc = (bp->acc <= bp->putlen ? \
			(num_l == 0 && bp->acc) : bp->acc - bp->putlen);
		bp->putlen += bp->acc + (num_l < 0 || bp->flag[3] || bp->flag[4]);
		bp->field = (bp->field <= bp->putlen ? 0 : bp->field - bp->putlen);
	}
	else if (bp->specifier >= 2 && bp->specifier <= 4)
	{
		bp->putlen = ft_get_ndigits_u(num_ul, bp->specifier - 2);
		bp->acc = (bp->acc <= bp->putlen ? \
			(num_ul == 0 && bp->acc) : bp->acc - bp->putlen);
		bp->putlen += bp->acc + \
			2 * (bp->flag[0] && num_ul != 0 && bp->specifier != 2);
		bp->field = (bp->field <= bp->putlen ? 0 : bp->field - bp->putlen);
	}
}

void	ft_pointer_print(va_list *ap, t_flag *bp)
{
	unsigned long long	num;

	bp->flag[0] = 1;
	bp->specifier = 3;
	if ((num = (unsigned long long)va_arg(*ap, void *)) == 0)
	{
		bp->acc = (bp->acc == -1 ? 1 : bp->acc);
		bp->putlen = 2 + bp->acc;
		bp->field = (bp->field <= bp->putlen ? 0 : bp->field - bp->putlen);
	}
	else
		ft_get_putlen(bp, 0, num);
	if (!bp->flag[2] && !bp->flag[1])
		ft_putchar_re_fd(' ', 1, bp->field);
	write(1, "0x", 2);
	ft_putchar_re_fd('0', 1, bp->acc + \
		(bp->flag[1] && !bp->flag[2] ? bp->field : 0));
	if (num)
		ft_putnbr_fd_u(num, 1, bp->specifier - 2);
	if (bp->flag[2])
		ft_putchar_re_fd(' ', 1, bp->field);
}

void	ft_unsigned_print(va_list *ap, t_flag *bp)
{
	unsigned long long num;

	if (bp->modifier == -1)
		num = (unsigned int)va_arg(*ap, int);
	else if (bp->modifier == 0)
		num = (unsigned short)va_arg(*ap, int);
	else if (bp->modifier == 1)
		num = (unsigned long)va_arg(*ap, long);
	else if (bp->modifier == 2)
		num = (unsigned char)va_arg(*ap, int);
	else
		num = (unsigned long long)va_arg(*ap, long long);
	ft_get_putlen(bp, 0, num);
	if (!bp->flag[2] && !bp->flag[1])
		ft_putchar_re_fd(' ', 1, bp->field);
	if (bp->flag[0] && num != 0 && bp->specifier != 2)
		write(1, (bp->specifier == 3 ? "0x" : "0X"), 2);
	ft_putchar_re_fd('0', 1, bp->acc + \
		(bp->flag[1] && !bp->flag[2] ? bp->field : 0));
	if (num)
		ft_putnbr_fd_u(num, 1, bp->specifier - 2);
	if (bp->flag[2])
		ft_putchar_re_fd(' ', 1, bp->field);
}

void	ft_int_print(va_list *ap, t_flag *bp)
{
	long long	num;

	if (bp->modifier == -1)
		num = va_arg(*ap, int);
	else if (bp->modifier == 0)
		num = (short int)va_arg(*ap, int);
	else if (bp->modifier == 1)
		num = va_arg(*ap, long);
	else if (bp->modifier == 2)
		num = (signed char)va_arg(*ap, int);
	else
		num = va_arg(*ap, long long);
	ft_get_putlen(bp, num, 0);
	if (!bp->flag[2] && !bp->flag[1])
		ft_putchar_re_fd(' ', 1, bp->field);
	ft_put_plus_minus(bp, num);
	ft_putchar_re_fd('0', 1, bp->acc + \
		(bp->flag[1] && !bp->flag[2] ? bp->field : 0));
	if (num)
		ft_putnbr_fd_u((num < 0 ? -1 : 1) * num, 1, 0);
	if (bp->flag[2])
		ft_putchar_re_fd(' ', 1, bp->field);
}
