/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:04:02 by fdacax-m          #+#    #+#             */
/*   Updated: 2023/12/19 13:23:53 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	char	*str;

	if (ptr[0] == '\0')
		return (NULL);
	i = 0;
	while (ptr[i] != '\n' && ptr[i])
		i++;
	j = i;
	if (ptr[i] == '\n')
		j++;
	str = ft_calloc(j + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strcpy(ptr, str, 1);
	return (str);
}

char	*ft_remaining(char *ptr)
{
	char	*r_str;
	int		i;

	i = 0;
	while (ptr[i] && ptr[i] != '\n')
		i++;
	if (ptr[i] == '\0')
	{
		free(ptr);
		return (NULL);
	}
	i++;
	r_str = ft_calloc(ft_strlen(ptr + i) + 1, sizeof(char));
	if (!r_str)
		return (NULL);
	ft_strcpy(ptr + i, r_str, 0);
	free(ptr);
	return (r_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*ptr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ptr = ft_get_file(ptr, fd);
	if (!ptr)
	{
		free(ptr);
		return (NULL);
	}
	line = ft_extracted_line(ptr);
	ptr = ft_remaining(ptr);
	return (line);
}
/*  #include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("get_next_line.c", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}  */
