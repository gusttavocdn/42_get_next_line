/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:42:51 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/22 08:46:35 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

// Standard Library headers
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

// Constants
# define BUFFER_SIZE 10
# define FD_OPEN_LIMIT 1024
# define NULL_BYTE 1
# define LINE_BREAK_BYTE 1
# define TRUE 1
# define FALSE 0

// Enum declarations

// Macro declarations

// Struct declarations
typedef struct s_node
{
	void			*data;
	struct s_node	*next;
}					t_node;

typedef struct s_queue
{
	int				size;
	t_node			*head;
	t_node			*tail;
}					t_queue;

// Function declarations
char *
get_next_line(int fd);
char				*ft_strchr(const char *str, int c);
size_t				ft_strlen(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strdup(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);

#endif // GET_NEXT_LINE_BONUS_H
