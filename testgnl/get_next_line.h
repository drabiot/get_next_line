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

typedef struct	s_list
{
	char		*content;
	char s_list	*next;
}				t_list;

char	*get_next_line(int fd);
void	read_buff(int fd, t_list **stash);
void	add_to_stash(t_list *stash, char *buff, int read);
void	add_to_line(t_list stash, char **line);
void	clean_stash(t_list **stash);

int	newline(t_list *stash);
t_list *get_last_node(t_list *stash);
void	create_line(t_list stash, char **line);
void	free_stash(t_list *stash);
int	 ft_strlen(const char *str);

#endif //GET_NEXT_LINE_H
