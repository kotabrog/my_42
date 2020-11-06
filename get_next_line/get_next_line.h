/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 12:28:09 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/07/06 22:35:49 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# define MAX_FD 4096
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE
# endif

int		get_next_line(int fd, char **line);
char	*ft_strchr_ex(const char *s, int c, ssize_t *len, int *flag);
char	*ft_strndup(const char *s, ssize_t n);
char	*ft_strjoin_ex(char *s1, char *s2, ssize_t n1, ssize_t n2);

#endif
