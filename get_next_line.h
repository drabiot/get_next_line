/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:08:37 by tchartie          #+#    #+#             */
/*   Updated: 2023/11/14 15:16:20 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>

int	new_line(char *str);
char	*ft_strjoin(char *s1, char *s2);
char    *ft_strcpy(char *dst, const char *src);
char	*ft_strcat(char *s1, char *s2, char *array);
size_t	ft_strlen(const char *str);

char	*get_next_line(int fd);

#endif //GET_NEXT_LINE_H