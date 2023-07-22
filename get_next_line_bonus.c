/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:43:05 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/22 08:54:07 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	read_file(int fd, t_queue *queue);
static char	*get_current_line(t_queue *queue);
static void	update_memory_pointer(char **memory_pointer, char *new_content);
void		ft_queue_enqueue(t_queue *queue, void *data);
t_node		*ft_queue_create_node(void *data);
void		ft_queue_del_node(t_node *node, void (*del)(void *));
t_node		*ft_queue_dequeue(t_queue *queue);

// typedef struct s_file_info
// {
// 	char	*buffer;
// 	char	*line;
// 	size_t	line_break_index;
// }			t_file_info;

char	*get_next_line(int fd)
{
	static t_queue	*file_data[FD_OPEN_LIMIT];
	char			*line;

	if (fd < 0 || fd > FD_OPEN_LIMIT || BUFFER_SIZE <= 0)
		return (NULL);
	if (!file_data[fd])
	{
		file_data[fd] = (t_queue *)malloc(sizeof(t_queue));
		if (!file_data[fd])
			return (NULL);
		file_data[fd]->size = 0;
	}
	read_file(fd, file_data[fd]);
	line = get_current_line(file_data[fd]);
	return (NULL);
}
static void	read_file(int fd, t_queue *queue)
{
	ssize_t	bytes_read;
	char	buffer[BUFFER_SIZE + NULL_BYTE];
	t_node	*current_node;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return ;
	buffer[bytes_read] = '\0';
	if (queue->size == 0)
		ft_queue_enqueue(queue, ft_strdup(buffer));
	current_node = queue->head;
	while (bytes_read && !ft_strchr(current_node->data, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		ft_queue_enqueue(queue, ft_strdup(buffer));
		current_node = current_node->next;
	}
}

static char	*get_current_line(t_queue *queue)
{
	char	*buffer;
	size_t	line_size;
	char	*line;

	if (queue->size == 0)
		return (NULL);
	buffer = ft_strdup(" ");
	while (queue->size > 1)
	{
		update_memory_pointer(&buffer, ft_strjoin(buffer, queue->head->data));
		ft_queue_del_node(ft_queue_dequeue(queue), free);
	}
	line_size = ft_strlen(buffer);
	while (*(char *)queue->head->data != '\n' && queue->head->data)
	{
		line_size++;
		queue->head->data++;
	}
	if (*(char *)queue->head->data == '\n')
		line_size++;
	line = (char *)malloc((line_size + NULL_BYTE) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcat(line, buffer, line_size + NULL_BYTE);
	ft_strlcat(line, queue->head->data, line_size + NULL_BYTE);
	update_memory_pointer(&queue->head->data,
							ft_strdup(ft_strchr(queue->head->data, '\n') + 1));
	return (line);
}

static void	update_memory_pointer(char **memory_pointer, char *new_content)
{
	char	*old_content;

	old_content = *memory_pointer;
	*memory_pointer = new_content;
	free(old_content);
	old_content = NULL;
}

void	ft_queue_enqueue(t_queue *queue, void *data)
{
	t_node	*new_node;

	if (queue->size == 0)
	{
		queue->head = ft_queue_create_node(data);
		queue->tail = queue->head;
		queue->size++;
		return ;
	}
	new_node = ft_queue_create_node(data);
	queue->tail->next = new_node;
	queue->tail = new_node;
	queue->size++;
}

t_node	*ft_queue_create_node(void *data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

t_node	*ft_queue_dequeue(t_queue *queue)
{
	t_node	*removed_node;

	if (queue->size == 0)
		return (NULL);
	queue->size--;
	removed_node = queue->head;
	queue->head = queue->head->next;
	if (queue->size == 0)
		queue->tail = NULL;
	removed_node->next = NULL;
	return (removed_node);
}

void	ft_queue_del_node(t_node *node, void (*del)(void *))
{
	if (!node)
		return ;
	del(node->data);
	free(node);
	node = NULL;
}
