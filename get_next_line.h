#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdlib.h>

/**
 * @brief This functions can read a line from a file descriptor.
 *
 * @param fd The file descriptor to read from.
 * @return The line read. NULL if there is nothing
 * else to read, or an error occurred.
 */
char	*get_next_line(int fd);

#endif //GET_NEXT_LINE_H
