/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 14:25:47 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/08/22 16:05:58 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_plus_minus(t_flag *bp, long long num_l)
{
	if (bp->specifier >= 5 && bp->specifier <= 7)
		num_l *= -1;
	if (num_l < 0)
		write(1, "-", 1);
	else if (bp->flag[3] || bp->flag[4])
		write(1, (bp->flag[4] ? "+" : " "), 1);
}

void	ft_n_storage(va_list *ap, t_flag *blueprint)
{
	if (blueprint->modifier == -1)
		*(unsigned int *)va_arg(*ap, unsigned int *) = blueprint->putnum;
	else if (blueprint->modifier == 0)
		*(unsigned short *)va_arg(*ap, unsigned short *) = blueprint->putnum;
	else if (blueprint->modifier == 1)
		*(unsigned long *)va_arg(*ap, unsigned long *) = blueprint->putnum;
	else if (blueprint->modifier == 2)
		*(unsigned char *)va_arg(*ap, unsigned char *) = blueprint->putnum;
	else
		*(unsigned long long *)va_arg(*ap, long long *) = blueprint->putnum;
	blueprint->field = 0;
}

int		ft_non_specifier(const char **start, const char **fmt, t_flag *bp)
{
	if (!**fmt)
		return (-1);
	bp->putlen = *fmt - *start;
	write(1, *start, bp->putlen);
	return (bp->putnum + bp->putlen);
}

void	ft_print_percent(t_flag *bp)
{
	bp->putlen = 1;
	bp->field = (bp->field <= bp->putlen ? 0 : bp->field - bp->putlen);
	if (!bp->flag[2] && !bp->flag[1])
		ft_putchar_re_fd(' ', 1, bp->field);
	ft_putchar_re_fd('0', 1, (bp->flag[1] && !bp->flag[2] ? bp->field : 0));
	write(1, "%%", 1);
	if (bp->flag[2])
		ft_putchar_re_fd(' ', 1, bp->field);
}

int		ft_dec_print(const char **start, const char **fmt, \
					va_list *ap, t_flag *bp)
{
	if (bp->specifier == -1)
		return (ft_non_specifier(start, fmt, bp));
	(*fmt)++;
	if (bp->specifier == 0 || bp->specifier == 1)
		ft_int_print(ap, bp);
	else if (bp->specifier >= 2 && bp->specifier <= 4)
		ft_unsigned_print(ap, bp);
	else if (bp->specifier >= 5 && bp->specifier <= 7)
		ft_double_print(ap, bp);
	else if (bp->specifier == 8)
		ft_char_print(ap, bp);
	else if (bp->specifier == 9)
		ft_string_print(ap, bp);
	else if (bp->specifier == 10)
		ft_pointer_print(ap, bp);
	else if (bp->specifier == 11)
		ft_n_storage(ap, bp);
	else
		ft_print_percent(bp);
	return (bp->putnum + bp->putlen + bp->field);
}
