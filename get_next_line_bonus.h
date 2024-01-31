/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:34:52 by fdacax-m          #+#    #+#             */
/*   Updated: 2023/12/19 16:01:45 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# ifndef FD_MAX_FILES
#  define FD_MAX_FILES 1024
# endif

char	*get_next_line(int fd);
char	*ft_get_file(char *ptr, int fd);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_extracted_line(char *s_buffer);
char	*ft_strcpy(char *src, char *dest, int nl_stop);
char	*ft_remaining(char *ptr);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_charcmp(char *str, int c);
size_t	ft_strlen(char *str);

#endif
