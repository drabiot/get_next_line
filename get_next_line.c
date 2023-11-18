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
	reading = 1;
	if (!buff)
		return (NULL);
	while (!new_line(stash) && reading != 0)
	{
		reading = (int)read(fd, buff, BUFFER_SIZE);
		if ((!stash && reading == 0) || reading == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[reading] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*add_to_line(char *stash)
{
	int	i;
	char	*line;

	i = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	line = ft_strcpy(line, stash);
	return (line);
}

char	*clean_stash(char *stash)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	if (!stash || !stash[0])
	{
		free(stash);
		return (NULL);
	}
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	len = ft_strlen(stash) - i;
	tmp = malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	tmp = ft_strcpy(tmp, &stash[i]);
	free(stash);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	stash = read_buff(fd, stash);
	line = add_to_line(stash);
	stash = clean_stash(stash);
	if (!stash && !line[0])
	{
		free(stash);
		return(NULL);
	}
	return (line);
}