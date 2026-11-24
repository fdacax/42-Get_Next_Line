/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedacax <fedacax@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 13:36:42 by fedacax           #+#    #+#             */
/*   Updated: 2026/11/24 16:54:47 by fedacax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_nl(int fd, char *ptr)
{
	char	*temp;
	int		read_bytes;
	
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);
	read_bytes = 1;
	while (!ft_charcmp(ptr) && read_bytes > 0)
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

char	*get_next_line(int fd)
{
	static char	*ptr;
	//char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	ptr = find_nl(fd, ptr);
	printf ("%s\n", ptr);
	return ("void");
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
/* 	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	} */
	close(fd);
	return(0);
}

/* 
	logica a ser implementada:
	usar read e aloc dntr do ptr ate != \n ou \0
	andar ate \n + 1;
	Salvar o resto dentro de uma variavel static.
*/