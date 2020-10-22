/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double_putlen.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 10:59:05 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/07/24 11:59:57 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_inf_nan(double d)
{
	unsigned long long ull;

	ull = *(unsigned long long *)&(d);
	if (ull == 0x7ff0000000000000 || ull == 0xfff0000000000000)
		return (1);
	if ((0x7ff0000000000000 < ull && ull <= 0x7fffffffffffffff) ||\
		(0xfff0000000000000 < ull && ull <= 0xffffffffffffffff))
		return (2);
	return (0);
}

int		ft_double_round_up(t_double *d, int n)
{
	d->num[n + 1] = 0;
	d->num[n] += 1;
	while (n > 0 && d->num[n] >= 10)
	{
		d->num[n--] = 0;
		d->num[n] += 1;
	}
	if ((d->num[n] != 1 || n != d->n_zero - 1) && d->num[0] != 10)
		return (0);
	if (d->num[n] == 1 && n == d->n_zero - 1)
	{
		d->n_zero--;
		return (1);
	}
	n = d->h_p + d->l_p + 1;
	while (n--)
		d->num[n + 1] = d->num[n];
	d->num[0] = 1;
	d->num[1] = 0;
	d->h_p += 1;
	return (2);
}

int		ft_double_round(t_flag *bp, t_double *d, int *flag)
{
	int target;
	int i;

	target = bp->acc + (bp->specifier == 5 ? d->n_zero : (d->h_p - 1));
	i = 0;
	if (d->num[target + 1] == 5)
	{
		while (d->num[target + 2 + i] == 0)
			i++;
		if (d->num[target + 2 + i] == -1 && !(d->num[target] % 2))
			d->num[target + 1] = 0;
	}
	if (d->num[target + 1] >= 5)
		i = ft_double_round_up(d, target);
	if (i)
	{
		bp->acc = bp->copy_acc;
		if (*flag)
			bp->specifier = 7;
		ft_double_putlen(bp, d, flag);
		return (-1);
	}
	return (0);
}

void	ft_double_put_cut(t_flag *bp, t_double *d)
{
	int i;
	int n;
	int temp;

	temp = (bp->specifier == 5 ? d->n_zero + 1 : d->h_p);
	i = 0;
	n = 0;
	while (d->num[temp + i] != -1 && i < bp->acc)
	{
		if (d->num[temp + i++] != 0)
			n = 0;
		else
			n++;
	}
	n = (bp->flag[0] ? 0 : n + bp->acc - i);
	bp->acc = (bp->acc - n < 0 ? 0 : bp->acc - n);
}

void	ft_double_putlen(t_flag *bp, t_double *d, int *flag)
{
	bp->putlen = (bp->flag[3] || bp->flag[4] || d->sign);
	bp->copy_acc = bp->acc;
	if (bp->specifier == 7)
	{
		bp->acc = (bp->acc == 0 ? 1 : bp->acc);
		bp->specifier = ((d->n_zero > 4 || d->h_p > bp->acc) ? 5 : 6);
		bp->acc += (bp->specifier == 5 ? -1 : d->n_zero - d->h_p);
		*flag = 1;
	}
	if (ft_double_round(bp, d, flag))
		return ;
	if (*flag)
		ft_double_put_cut(bp, d);
	bp->putlen += bp->acc - (bp->acc == 0 && !bp->flag[0]);
	if (bp->specifier == 5)
		bp->putlen += 6 + (d->h_p >= 100 || d->n_zero >= 100) \
			+ (d->h_p >= 1000 || d->n_zero >= 1000);
	else if (bp->specifier == 6)
		bp->putlen += d->h_p + 1;
	bp->field = (bp->field <= bp->putlen ? 0 : bp->field - bp->putlen);
}
