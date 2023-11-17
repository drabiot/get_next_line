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

char	*read_buff(int fd, char *stash)
{
	char	*buff;
	int		reading;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!new_line(stash))
	{
		reading = (int)read(fd, buff, BUFFER_SIZE);
		buff[reading] = '\0';
		if ((stash == 0 && reading == 0) || reading == -1)
		{
			free(buff);
			return (NULL);
		}
		stash = ft_strjoin(stash, buff);
	}
	return (stash);
}

char	*add_to_line(char *stash)
{
	int	i;
	char	*line;

	i = 0;
	while (stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, stash, i + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_buff(fd, stash);
	line = add_to_line(stash);
	return (line);	
}
