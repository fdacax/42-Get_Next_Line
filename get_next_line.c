/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedacax <fedacax@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 13:36:42 by fedacax           #+#    #+#             */
/*   Updated: 2026/11/27 16:21:41 by fedacax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(char *ptr, int fd)
{
	char	*temp;
	int		read_bytes;

	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);
	read_bytes = 1;
	while (!find_sep(ptr) && read_bytes > 0)
	{
		read_bytes = read(fd, temp, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			if (ptr)
				free(ptr);
			free(temp);
			return (NULL);
		}
		temp[read_bytes] = 0;
		ptr = ft_strjoin(ptr, temp);
	}
	free(temp);
	return (ptr);
}

char	*extract_line(char *ptr)
{
	char	*str;
	int		i;

	i = 0;
	if (!ptr || !ptr[i])
		return (NULL);
	while (ptr[i] && ptr[i] != SEPARATOR)
		i++;
	if (ptr[i] == SEPARATOR)
		i++;
	str = ft_calloc((i + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (--i >= 0)
		str[i] = ptr[i];
	return (str);
}

char	*update_stash(char *ptr)
{
	char	*str;
	int		i;

	i = 0;
	while (ptr[i] && ptr[i] != SEPARATOR)
		i++;
	if (!ptr[i])
	{
		free(ptr);
		return (NULL);
	}
	i++;
	str = ft_calloc((ft_strlen(&ptr[i]) + 1), sizeof(char));
	if (!str)
		return (NULL);
	str = ft_strjoin(str, &ptr[i]);
	free(ptr);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*ptr;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ptr = read_file(ptr, fd);
	if (!ptr)
	{
		free(ptr);
		return (NULL);
	}
	line = extract_line(ptr);
	ptr = update_stash(ptr);
	return (line);
}

/* int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
		usleep(100000);
		free(line);
	}
	close (fd);
	return (0);
} */
