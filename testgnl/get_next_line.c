/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:08:18 by tchartie          #+#    #+#             */
/*   Updated: 2023/11/14 15:14:57 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*stash;
	char			*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	read_buff(fd, &stash);
	if (!stash)
		return (NULL);
	add_to_line(stash, &line);
	clean_stash(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
	
}

void	read_buff(int fd, t_list **stash)
{
	char	*buff;
	int		read;
	
	read = 1;
	while (!newline(*stash) && read != 0)
	{
		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return ;
		read = (int)read(fd, buff, BUFFER_SIZE);
		if (!*stash && read == 0) || read = -1)
		{
			free(buff);
			return ;
		}
		buff[read] = '\0';
		add_to_stash(stash, buff, read);
		free(buff);
	}
}

void	add_to_stash(t_list *stash, char *buff, int read)
{
	int		i;
	t_list	*current;
	t_list	*new_node;
	
	i = 0;
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (read + 1));
	if (!(new_node->content))
		return ;
	while (buff[i] && i < read)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (!*stash)
	{
		*stash = new_node;
		return ;
	}
	current = get_last_node(*stash);
	current->next = new_node;
}

void	add_to_line(t_list stash, char **line)
{
	int	i;
	int	j;
	
	if (!stash)
		return ;
	create_line(stash, line);
	if (!*line)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] = '\n')
			{
				*line[j++] = stash->content[i];
				break ;
			}
			*line[j++] = stash->content[i++];
		}
		stash = stash->next
	}
	*line[j] = '\0';
}

void	clean_stash(t_list **stash)
{
	t_list	*current;
	t_list	*clean_node;
	int		i;
	int		j;
	
	clean_node = malloc(sizeof(t_list));
	if (!stash || !clean_node)
		return ;
	clean_node->next = NULL;
	current = get_last_node(*stash);
	i = 0;
	while (current->content[i] && current->content[i] != '\n')
		i++;
	if (current->content && current->content[i] != '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * (ft_strlen(current->content) - i) + 1)
	if (!clean_node->content)
		return ;
	j = 0;
	while (current->content[i]
		clean_node->content[j++] = last-content[i++];
	clean_node-content[j] = '\0';
	free_stash(*stash);
	*stash = clean_node;
}

