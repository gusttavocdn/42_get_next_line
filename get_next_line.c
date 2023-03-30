#include "get_next_line.h"

static char *s_format_line(char **buf);

char *get_next_line(int fd)
{
	static char *buffer = NULL;
	char read_buffer[BUFFER_SIZE + 1];
	char *line;
	char *tmp_buffer;
	size_t readed_bytes;

	readed_bytes = read(fd, read_buffer, BUFFER_SIZE);
	while ((readed_bytes > 0))
	{
		read_buffer[readed_bytes] = '\0';
		if (!buffer) buffer = ft_strjoin("", read_buffer);
		else
		{
			tmp_buffer = ft_strjoin(buffer, read_buffer);
			free(buffer);
			buffer = tmp_buffer;
		}
		if (ft_strchr(buffer, '\n'))
			break;
		readed_bytes = read(fd, read_buffer, BUFFER_SIZE);
	}
	line = s_format_line(&buffer);
	return (line);
}

static char *s_format_line(char **buf)
{
	char *line;
	char *str;
	size_t i;

	if (*buf == NULL)
		return (NULL);

	str = *buf;
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	line = ft_substr(str, 0, i + 1);
	*buf = ft_substr(&str[i + 1], 0, ft_strlen(&str[i]));
	if (!(*buf))
		free(*buf);
	free(str);
	return (line);
}