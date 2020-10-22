/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 13:31:48 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/06/28 14:34:24 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		n;

	if (lst == NULL)
		return (0);
	n = 1;
	while (lst->next != NULL)
	{
		n++;
		lst = lst->next;
	}
	return (n);
}
