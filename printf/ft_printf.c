/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:53:58 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/08/25 18:38:01 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_substr_to_num(const char **fmt, va_list *ap, int mode, t_flag *bp)
{
	int	num;

	num = -1;
	if (**fmt == '*')
	{
		num = va_arg(*ap, int);
		if (num < 0 && !mode)
		{
			num *= -1;
			bp->flag[2] = 1;
		}
		else if (num < 0)
			num = -1;
		(*fmt)++;
	}
	else if (mode || ft_isdigit(**fmt))
	{
		num = 0;
		while (ft_isdigit(**fmt))
			num = num * 10 + (*((*fmt)++) - '0');
	}
	return (num);
}

void	ft_init_flag(t_flag *s, int n)
{
	s->flag[0] = 0;
	s->flag[1] = 0;
	s->flag[2] = 0;
	s->flag[3] = 0;
	s->flag[4] = 0;
	s->field = -1;
	s->acc = -1;
	s->modifier = -1;
	s->specifier = -1;
	s->putnum = (n < 0 ? 0 : n);
	s->putlen = 0;
}

void	ft_proc_per(const char **start, const char **fmt, int *n, va_list *ap)
{
	int		num;
	t_flag	blueprint;

	(*fmt)++;
	ft_init_flag(&blueprint, *n);
	while ((num = ft_strchr_n("#0- +", **fmt)) >= 0)
	{
		blueprint.flag[num] = 1;
		(*fmt)++;
	}
	blueprint.field = ft_substr_to_num(fmt, ap, 0, &blueprint);
	if (**fmt == '.')
	{
		(*fmt)++;
		blueprint.acc = ft_substr_to_num(fmt, ap, 1, &blueprint);
	}
	if ((num = ft_strchr_n("hl", **fmt)) >= 0)
		if (num == ft_strchr_n("hl", *(++(*fmt))))
			num += 2;
	if ((blueprint.modifier = num) >= 2)
		(*fmt)++;
	blueprint.specifier = ft_strchr_n("diuxXefgcspn%", **fmt);
	num = ft_dec_print(start, fmt, ap, &blueprint);
	*n = ((*n == 0 || num >= 0) ? num : *n);
}

void	ft_print_str(const char **start, const char **fmt, int *n)
{
	while (**fmt != '%' && **fmt)
		(*fmt)++;
	write(1, *start, *fmt - *start);
	*n += *fmt - *start;
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			n;
	const char	*start;

	n = 0;
	va_start(ap, fmt);
	if (fmt == NULL)
		n = -1;
	while (n >= 0 && *fmt)
	{
		start = fmt;
		if (*start != '%')
			ft_print_str(&start, &fmt, &n);
		else
			ft_proc_per(&start, &fmt, &n, &ap);
	}
	va_end(ap);
	return (n);
}
