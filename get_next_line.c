/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:08:18 by tchartie          #+#    #+#             */
/*   Updated: 2023/11/16 19:30:16 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	read_buff(fd, stash);
	add_to_line(stash, line);
	return (line);	
}

void	read_buff(int fd, char *stash)
{
	char	*buff;
	int		reading;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return ;
	while (!new_line(stash))
	{
		reading = (int)read(fd, buff, BUFFER_SIZE);
		buff[reading] = '\0';
		if ((stash == 0 && reading == 0) || reading == -1)
		{
			free(buff);
			return ;
		}
		ft_strjoin(stash, buff);
	}
}

void	add_to_line(char *stash, char *line)
{
	int	i;

	i = 0;
	while (stash[i] != '\n')
		i++;
	ft_strlcpy(line, stash, (i + 1));
}
