/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 18:14:47 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/07/24 11:33:16 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_set_double(t_double *d, int point)
{
	int i;
	int arr[BUF];
	int temp;

	ft_reset_arr(arr, d->l_p + 1);
	arr[0] = 1;
	point = point + d->l_p - 1;
	i = -1;
	while (++i < d->l_p)
	{
		temp = point - i;
		ft_halve_arr(arr, d->l_p);
		if (temp < 53 && temp >= 0 && (d->val & (1ULL << temp)))
			ft_add_arr(arr, d->num, d->l_p);
	}
	ft_reset_arr(arr, BUF);
	arr[BUF - 1] = 1;
	i = -1;
	while (++i <= d->exp)
	{
		if (i > 0)
			ft_double_arr(arr, &(d->h_p));
		if (52 - d->exp + i >= 0 && (d->val & (1ULL << (52 - d->exp + i))))
			ft_add_arr2(arr, d->num, &(d->h_p), d->l_p);
	}
}

void	ft_dump_double(t_double *d)
{
	unsigned long long temp;

	if (d->d == 0.0 || d->d == -0.0)
	{
		d->sign = (*(unsigned long long *)&(d->d) & (1ULL << 63)) >> 63;
		d->h_p = 1;
		d->l_p = 1;
		d->n_zero = 0;
		ft_reset_arr(d->num, BUF);
		d->num[2] = -1;
		return ;
	}
	temp = *(unsigned long long *)&(d->d);
	d->val = temp & ((1ULL << 52) - 1);
	d->val = d->val | (1ULL << 52);
	temp >>= 52;
	d->exp = temp & ((1 << 11) - 1);
	d->exp -= 1023;
	temp >>= 11;
	d->sign = temp;
	ft_reset_arr(d->num, BUF);
	d->h_p = 1;
	d->n_zero = 0;
}

void	ft_b_to_array(t_double *d)
{
	int i;
	int n;

	ft_dump_double(d);
	if (d->d == 0.0 || d->d == -0.0)
		return ;
	i = 0;
	while (i < 52 && !(d->val & (1ULL << i)))
		i++;
	d->l_p = -1 * d->exp + 52 - i;
	d->l_p = (d->l_p < 0 ? 0 : d->l_p);
	ft_set_double(d, i);
	n = BUF - d->l_p - d->h_p;
	i = -1;
	while (++i + n < BUF)
	{
		d->num[i] = d->num[i + n];
		d->num[i + n] = 0;
	}
	d->num[i] = -1;
	i = 0;
	while (d->num[i++] == 0)
		(d->n_zero)++;
}

void	ft_double_put(t_flag *bp, t_double *d)
{
	int i;

	i = 0;
	if (bp->specifier == 5)
		ft_putnbr_fd(d->num[d->n_zero], 1);
	else
		while (i < d->h_p)
			ft_putnbr_fd(d->num[i++], 1);
	if (bp->flag[0] || bp->acc)
		write(1, ".", 1);
	i = 0;
	if (bp->specifier == 5)
		while (i < bp->acc && d->n_zero + 1 + i < d->h_p + d->l_p)
			ft_putnbr_fd(d->num[d->n_zero + 1 + i++], 1);
	else
		while (i < bp->acc && i < d->l_p)
			ft_putnbr_fd(d->num[d->h_p + i++], 1);
	ft_putchar_re_fd('0', 1, bp->acc - i);
	if (bp->specifier == 6)
		return ;
	i = d->h_p - d->n_zero - 1;
	write(1, (i < 0 ? "e-" : "e+"), 2);
	write(1, "0", ((i < 0 ? -1 * i : i) < 10));
	ft_putnbr_fd((i < 0 ? -1 * i : i), 1);
}

void	ft_double_print(va_list *ap, t_flag *bp)
{
	t_double	d;
	int			flag;

	d.d = va_arg(*ap, double);
	if (ft_is_inf_nan(d.d))
	{
		bp->copy_acc = (*(unsigned long long *)&(d.d) & (1ULL << 63)) >> 63;
		bp->modifier = ft_is_inf_nan(d.d);
		ft_string_print(NULL, bp);
		return ;
	}
	ft_b_to_array(&d);
	bp->acc = (bp->acc == -1 ? 6 : bp->acc);
	flag = 0;
	ft_double_putlen(bp, &d, &flag);
	if (!bp->flag[2] && !bp->flag[1])
		ft_putchar_re_fd(' ', 1, bp->field);
	ft_put_plus_minus(bp, d.sign);
	ft_putchar_re_fd('0', 1, (bp->flag[1] && !bp->flag[2] ? bp->field : 0));
	ft_double_put(bp, &d);
	if (bp->flag[2])
		ft_putchar_re_fd(' ', 1, bp->field);
}
