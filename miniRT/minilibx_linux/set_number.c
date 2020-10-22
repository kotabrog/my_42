/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 21:33:47 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/09/29 19:28:34 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		set_int(char **s)
{
	int num;

	num = 0;
	while (ft_isdigit(**s))
		num = num * 10 + (*((*s)++) - '0');
	return (num);
}

double	set_double(char **s)
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
	num = set_int(s);
	if (**s == '.')
	{
		(*s)++;
		while (**s == '0')
			(*s)++;
		p = *s;
		d = set_int(s);
		if (d != 0)
			num += pow(10, -1 * (int)(*s - p)) * d;
	}
	return (num * sign);
}

int		set_color(char **s)
{
	int r;
	int g;
	int b;

	if (!ft_isdigit(**s))
		r = -1;
	else
		r = set_int(s);
	if (**s == ',')
		(*s)++;
	else
		r = -1;
	if (!ft_isdigit(**s))
		r = -1;
	g = set_int(s);
	if (**s == ',')
		(*s)++;
	else
		r = -1;
	if (!ft_isdigit(**s))
		r = -1;
	b = set_int(s);
	return (ft_isin_int(0, r, 255) && ft_isin_int(0, g, 255) \
			&& ft_isin_int(0, b, 255) ? create_trgb(0, r, g, b) : -1);
}

t_vec	set_vec(char **s)
{
	t_vec	vec;

	vec.x_int = 0;
	vec.x = set_double(s);
	if (**s == ',')
		(*s)++;
	else
		vec.x_int = 1;
	vec.y = set_double(s);
	if (**s == ',')
		(*s)++;
	else
		vec.x_int = 1;
	vec.z = set_double(s);
	if (isinf(vec.x) || isinf(vec.y) || isinf(vec.z))
		vec.x_int = 1;
	return (vec);
}

void	set_object(t_object **ob, int *n_ob)
{
	int			i;
	t_object	*obs;

	i = 0;
	if ((obs = (t_object *)malloc((*n_ob + 1) * sizeof(t_object))) == NULL)
	{
		*n_ob *= -1;
		return ;
	}
	while (i < *n_ob)
	{
		obs[i] = (*ob)[i];
		i++;
	}
	free(*ob);
	*ob = obs;
	(*n_ob)++;
}
