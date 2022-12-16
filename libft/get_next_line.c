/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:35:25 by bgresse           #+#    #+#             */
/*   Updated: 2022/12/16 17:04:31 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*r_file(char *rest, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		read_bytes;

	read_bytes = 1;
	while (!is_newline(rest, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (NULL);
		buffer[read_bytes] = '\0';
		rest = rest_join_buffer(rest, buffer);
	}
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (read(fd, &line, 0) == -1)
		return (free(rest), NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = r_file(rest, fd);
	if (!rest)
		return (NULL);
	line = get_before_newline_character(rest);
	rest = get_after_newline_character(rest);
	return (line);
}
