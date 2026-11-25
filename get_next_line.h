/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedacax <fedacax@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 13:33:58 by fedacax           #+#    #+#             */
/*   Updated: 2026/11/25 17:06:11 by fedacax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef SEPARATOR
#  define SEPARATOR '\n'
# endif

/* ************************************************************************** */
/*                                    main                                    */
/* ************************************************************************** */

char	*get_next_line(int fd);
int		main(void);

/* ************************************************************************** */
/*                                   utils                                    */
/* ************************************************************************** */

size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char *s1, const char *s2);
int		ft_charcmp(const char *str);

#endif