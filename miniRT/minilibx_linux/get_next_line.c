/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:10:08 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/19 22:36:40 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char		*ft_strndup(const char *s, ssize_t n)
{
	char	*p;

	if (s == NULL)
		n = 0;
	else if (n < 0)
		n = ft_strlen(s);
	if ((p = (char *)malloc(n + 1)) == NULL)
		return (NULL);
	ft_strcpy(p, s, n);
	p[n] = 0;
	return (p);
}

char	*ft_strjoin_ex(char *s1, char *s2, ssize_t n1, ssize_t n2)
{
	char	*p;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (n1 < 0)
		n1 = ft_strlen(s1);
	if (n2 < 0)
		n2 = ft_strlen(s2);
	if ((p = (char *)malloc(n1 + n2 + 1)) == NULL)
		return (NULL);
	ft_strcpy(p, s1, n1);
	ft_strcpy(p + n1, s2, n2);
	p[n1 + n2] = 0;
	return (p);
}

char	*read_join(int fd, char **line, ssize_t *n, int *flag)
{
	ssize_t	line_size;
	ssize_t	m;
	char	*buf;
	char	*rest;
	char	*temp;

	if ((buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))) == NULL)
		*n = -1;
	line_size = *n;
	rest = NULL;
	while (!(*flag) && *n >= 0 && (*n = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[*n] = 0;
		if ((rest = ft_strchr_ex(buf, '\n', &m, flag)) != NULL &&
			(rest = ft_strndup(rest, *n - m - 1)) == NULL)
			*n = -1;
		if ((temp = ft_strjoin_ex(*line, buf, line_size, m)) == NULL)
			*n = -1;
		free(*line);
		*line = temp;
		line_size += m;
	}
	free(buf);
	return (rest);
}

int		get_next_line(int fd, char **line)
{
	static char	*fd_array[MAX_FD];
	char		*rest;
	ssize_t		n;
	int			find_flag;

	find_flag = 0;
	if (fd < 0 || MAX_FD <= fd || line == NULL)
		return (-1);
	rest = ft_strchr_ex(fd_array[fd], '\n', &n, &find_flag);
	if (rest && (rest = ft_strndup(rest, -1)) == NULL)
		n = -1;
	if (n >= 0 && (*line = ft_strndup(fd_array[fd], n)) == NULL)
		n = -1;
	if (n >= 0 && !find_flag)
		rest = read_join(fd, line, &n, &find_flag);
	free(fd_array[fd]);
	fd_array[fd] = rest;
	if (n < 0)
	{
		free(*line);
		free(fd_array[fd]);
		*line = NULL;
		return (-1);
	}
	return (find_flag);
}
