/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:10:23 by fdacax-m          #+#    #+#             */
/*   Updated: 2023/12/19 13:23:18 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_charcmp(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strcpy(char *src, char *dest, int flag)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		if (flag && src[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;
	size_t			len;

	len = nmemb * size;
	ptr = malloc(len);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	len;
	char	*ptr;
	int		i;
	int		j;

	len = ft_strlen(str1) + ft_strlen(str2);
	ptr = ft_calloc((len + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (str1 && str1[i])
	{
		ptr[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2 && str2[j])
		ptr[i++] = str2[j++];
	free(str1);
	return (ptr);
}
