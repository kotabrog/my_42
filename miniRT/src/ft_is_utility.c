/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:43:45 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/17 22:05:25 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int		ft_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n' ||\
			c == '\r' || c == '\t' || c == '\v');
}

void	ft_advance_isspace(char **s)
{
	while (ft_isspace(**s))
		(*s)++;
}

int		is_rt_file(const char *file)
{
	int i;

	i = ft_strlen(file);
	return (!(i < 4 || file[i - 3] != '.' || \
			file[i - 2] != 'r' || file[i - 1] != 't'));
}
