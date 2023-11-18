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

int	new_line(char *str)
{
	int	i;
	
	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*array;

	array = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!array)
		return (NULL);
	if (s1)
		ft_strlcpy(array, s1, ft_strlen(s1) + 1);
	if (s2)
		ft_strlcpy(array + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free(s1);
	return (array);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (src[count])
		count++;
	if (size > 0)
	{
		while (src[i] && (i < size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (count);
}

size_t	ft_strlen(const char *str)
{
	size_t	size;

	size = 0;
	if (!str)
		return (0);
	while (str[size])
		size++;
	return (size);
}
