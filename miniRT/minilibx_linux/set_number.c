/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 21:33:47 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/20 13:43:04 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		set_int(char **s, int *flag)
{
	int num;
	int i;

	num = 0;
	i = 0;
	while (ft_isdigit(**s))
	{
		if (++i <= 8)
			num = num * 10 + (**s - '0');
		else
			*flag = ERROR_OVER;
		++(*s);
	}
	return (num);
}

double	set_double(char **s, int *flag)
{
	int		d;
	double	num;
	int		sign;
	char	*p;

	sign = 1;
	if (**s == '-')
	{
		sign = -1;
		(*s)++;
	}
	if (!ft_isdigit(**s))
		return (INFINITY);
	num = set_int(s, flag);
	if (**s == '.')
	{
		(*s)++;
		p = *s;
		while (**s == '0')
			(*s)++;
		d = set_int(s, flag);
		num += pow(10, -1 * (int)(*s - p)) * d;
	}
	return (num * sign);
}

int		set_color(char **s, int *flag)
{
	int r;
	int g;
	int b;

	if (!ft_isdigit(**s))
		r = -1;
	else
		r = set_int(s, flag);
	if (**s == ',')
		(*s)++;
	else
		r = -1;
	if (!ft_isdigit(**s))
		r = -1;
	g = set_int(s, flag);
	if (**s == ',')
		(*s)++;
	else
		r = -1;
	if (!ft_isdigit(**s))
		r = -1;
	b = set_int(s, flag);
	return (ft_isin_int(0, r, 255) && ft_isin_int(0, g, 255) \
			&& ft_isin_int(0, b, 255) ? create_trgb(0, r, g, b) : -1);
}

void	set_vec(t_vec *vec, char **s, int *flag, int error_num)
{
	vec->x = set_double(s, flag);
	if (**s == ',')
		(*s)++;
	else
		*flag = error_num;
	vec->y = set_double(s, flag);
	if (**s == ',')
		(*s)++;
	else
		*flag = error_num;
	vec->z = set_double(s, flag);
	if (isinf(vec->x) || isinf(vec->y) || isinf(vec->z))
		*flag = error_num;
}

void	set_object(t_object **ob, int *n_ob, int *flag)
{
	int			i;
	t_object	*obs;

	i = 0;
	if ((obs = (t_object *)malloc((*n_ob + 1) * sizeof(t_object))) == NULL)
	{
		*flag = ERROR_MALLOC;
		return ;
	}
	while (i < *n_ob)
	{
		obs[i] = (*ob)[i];
		i++;
	}
	free(*ob);
	*ob = obs;
	++(*n_ob);
}
