#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

/**
 * @brief This functions can read a line from a file descriptor.
 *
 * @param fd The file descriptor to read from.
 * @return The line read. NULL if there is nothing
 * else to read, or an error occurred.
 */
char *get_next_line(int fd);

char *ft_strchr(const char *str, int c);

char *ft_strjoin(char const *s1, char const *s2);

void ft_bzero(void *s, size_t n);

void *ft_calloc(size_t nmemb, size_t size);

char *ft_substr(char const *s, unsigned int start, size_t len);

size_t ft_strlen(const char *s);

#endif //GET_NEXT_LINE_H
