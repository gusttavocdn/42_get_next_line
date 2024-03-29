/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:42:51 by gusda-si          #+#    #+#             */
/*   Updated: 2023/08/04 17:07:28 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

// Standard Library headers
# include <stdlib.h>
# include <unistd.h>

// Constants
# define FD_OPEN_LIMIT 1024
# define NULL_BYTE 1
# define LINE_BREAK_BYTE 1
# define TRUE 1
# define FALSE 0
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Function declarations
char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);

#endif // GET_NEXT_LINE_BONUS_H
