#include "get_next_line.h"

static char *s_format_line(char **buf);

static void s_read_content(int fd, char **acc, char *buffer);

char *get_next_line(int fd)
{
	static char *acc_buffer[1024];
	char current_buffer[BUFFER_SIZE + 1];
	char *line;

	if ((fd < 0 || fd > 1024) != 0)
		return (NULL);
	s_read_content(fd, &acc_buffer[fd], current_buffer);
	line = s_format_line(&acc_buffer[fd]);
	return (line);
}

static void s_read_content(int fd, char **acc, char *buffer)
{
	char *tmp_buffer;
	size_t readed_bytes;

	readed_bytes = read(fd, buffer, BUFFER_SIZE);
	while ((readed_bytes > 0))
	{
		buffer[readed_bytes] = '\0';
		if (!(*acc))
			*acc = ft_strjoin("", buffer);
		else
		{
			tmp_buffer = ft_strjoin(*acc, buffer);
			free(*acc);
			*acc = tmp_buffer;
		}
		if (ft_strchr(*acc, '\n'))
			break;
		readed_bytes = read(fd, buffer, BUFFER_SIZE);
	}
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
	*buf = ft_substr(str, (i + 1), ft_strlen(str));
	if ((*buf)[0] == '\0')
	{
		free(*buf);
		*buf = NULL;
	}
	free(str);
	return (line);
}