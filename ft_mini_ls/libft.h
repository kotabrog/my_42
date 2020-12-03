/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 12:28:09 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/03 22:22:58 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <dirent.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <errno.h>
# include <stdio.h>

# define BUFFER 1000
# define ERROR_MESSAGE "./ft_mini_ls: ."

typedef struct	s_fi
{
	char	*name;
	time_t	time;
	time_t	nano_time;
}				t_fi;

size_t			ft_strlen(const char *s);
int				ft_fi_cmp(const t_fi *fi1, const t_fi *fi2);

#endif
