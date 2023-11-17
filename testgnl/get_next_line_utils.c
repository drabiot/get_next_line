/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:08:29 by tchartie          #+#    #+#             */
/*   Updated: 2023/11/14 14:08:31 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	newline(t_list *stash)
{
	int		i;
	t_list	*current;
	
	if (!stash)
		return (0);
	current = get_last_node(stash);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list *get_last_node(t_list *stash)
{
	t_list	*current;
	
	current = stash;
	while (current && current->next)
		current = current->next;
	return (current);
}

void	create_line(t_list stash, char **line)
{
	int i;
	int	len;
	
	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		stash = stash->next;
	}
	*line = (char *)malloc(sizeof(char) * (len + 1));
	if (!*line)
		return ;
}

void	free_stash(t_list *stash)
{
	t_list	*current;
	t_list	*next;
	
	current = stash;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

int ft_strlen(const char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}
