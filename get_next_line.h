/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:19:38 by fdacax-m          #+#    #+#             */
/*   Updated: 2023/12/19 13:29:56 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_get_file(char *ptr, int fd);
char	*ft_extracted_line(char *ptr);
char	*ft_remaining(char *ptr);
char	*ft_strcpy(char *src, char *dest, int flag);
char	*ft_strjoin(char *str1, char *str2);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_charcmp(char *str, int c);
size_t	ft_strlen(char *str);

#endif