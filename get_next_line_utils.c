#include "get_next_line.h"

char *ft_strchr(const char *str, int c)
{
	char *s;

	if (!str)
		return (NULL);

	s = (char *) str;
	while (*s)
	{
		if (*s == (char) c)
			return (s);
		s++;
	}
	if (!c && !(*s))
		return (s);
	return (NULL);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	size_t str_len;
	char *str;
	size_t i;
	size_t j;

	if (!s1 || !s2)
		return (NULL);
	str_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = ft_calloc(str_len, sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}

size_t ft_strlen(const char *s)
{
	size_t length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	size_t s_len;
	size_t substr_len;
	char *substr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	substr_len = s_len - (size_t) start;
	if (start > s_len)
		return ((char *) ft_calloc(1, sizeof(char)));
	if (substr_len > len)
		substr = (char *) ft_calloc((len + 1), sizeof(char));
	else
		substr = (char *) ft_calloc((substr_len + 1), sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (s[start] && len--)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

void *ft_calloc(size_t nmemb, size_t size)
{
	void *pointer;
	size_t bytes_size;
	unsigned char *p;

	if (nmemb >= 18446744073709551615UL || size >= 18446744073709551615UL
		|| nmemb * size >= 18446744073709551615UL)
		return (NULL);
	pointer = malloc(nmemb * size);
	if (pointer == NULL)
		return (NULL);

	bytes_size = nmemb * size;
	p = pointer;
	while (bytes_size--)
		*p++ = 0;
	return (pointer);
}
