/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:37:25 by dmeirele          #+#    #+#             */
/*   Updated: 2023/12/19 15:58:06 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_file(char *ptr, int fd)
{
	char	*str_temp;
	int		bytes_read;

	str_temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!str_temp)
		return (NULL);
	bytes_read = 1;
	while (!ft_charcmp(ptr, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, str_temp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			if (ptr)
				free(ptr);
			free(str_temp);
			return (NULL);
		}
		str_temp[bytes_read] = '\0';
		ptr = ft_strjoin(ptr, str_temp);
	}
	free(str_temp);
	return (ptr);
}

char	*ft_extracted_line(char *ptr)
{
	int		i;
	int		j;
	char	*line;

	if (ptr[0] == '\0')
		return (NULL);
	i = 0;
	while (ptr[i] != '\n' && ptr[i])
		i++;
	j = i;
	if (ptr[i] == '\n')
		j++;
	line = ft_calloc(j + 1, sizeof(char));
	if (!line)
		return (NULL);
	ft_strcpy(ptr, line, 1);
	return (line);
}

char	*ft_remaining(char *ptr)
{
	char	*rest;
	int		start;

	start = 0;
	while (ptr[start] && ptr[start] != '\n')
		start++;
	if (ptr[start] == '\0')
	{
		free(ptr);
		return (NULL);
	}
	start++;
	rest = ft_calloc(ft_strlen(ptr + start) + 1, sizeof(char));
	if (!rest)
		return (NULL);
	ft_strcpy(ptr + start, rest, 0);
	free(ptr);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*ptr[FD_MAX_FILES];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ptr[fd] = ft_get_file(ptr[fd], fd);
	if (!ptr[fd])
	{
		free(ptr[fd]);
		return (NULL);
	}
	line = ft_extracted_line(ptr[fd]);
	ptr[fd] = ft_remaining(ptr[fd]);
	return (line);
}
