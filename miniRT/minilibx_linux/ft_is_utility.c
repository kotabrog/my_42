/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:43:45 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/09/20 12:09:19 by ksuzuki          ###   ########.fr       */
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
