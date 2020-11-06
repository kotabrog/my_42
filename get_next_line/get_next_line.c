/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:10:08 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/08/22 12:52:29 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
