/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:43:55 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/22 08:46:27 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief This functions founds an c character in a string.
 *
 * @param s The string to search
 * @param c The char to search for in the string
 * @return Returns a pointer to the character if found.
 * @return Returns NULL if not found.
 * @return If c == '\0' returns a pointer to the end of the string.
 */
char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (unsigned char)c)
		return ((char *)str);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc((len + NULL_BYTE) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (s1 && *s1 != '\0')
		*new_str++ = *s1++;
	while (s2 && *s2 != '\0')
		*new_str++ = *s2++;
	*new_str = '\0';
	return ((new_str - len));
}

size_t	ft_strlen(const char *s)
{
	char	*s_begin;

	if (!s)
		return (0);
	s_begin = (char *)s;
	while (*s != '\0')
		s++;
	return ((size_t)(s - s_begin));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	str_len;

	str_len = ft_strlen(src);
	if ((size <= 0) | !dst)
		return (str_len);
	while (*src != '\0' && size-- > 1)
		*dst++ = *src++;
	*dst = '\0';
	return (str_len);
}

char	*ft_strdup(const char *s)
{
	char	*new_str;
	size_t	size;

	size = ft_strlen(s);
	new_str = (char *)malloc((size + NULL_BYTE) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (*s != '\0')
		*new_str++ = *s++;
	*new_str = '\0';
	return ((new_str - size));
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	final_len;

	src_len = ft_strlen(src);
	if (!dst || size == 0)
		return (src_len + size);
	dest_len = ft_strlen(dst);
	final_len = dest_len + src_len;
	if (size > dest_len)
	{
		while ((*src != '\0') && (dest_len < size - 1))
			dst[dest_len++] = *src++;
		dst[dest_len] = '\0';
		return (final_len);
	}
	return (src_len + size);
}
