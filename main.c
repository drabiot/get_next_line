/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:31:31 by tchartie          #+#    #+#             */
/*   Updated: 2023/11/16 19:32:57 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int		fd;
	char	*line;

	fd = open("test", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
}
