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

int    main(void)
{
    char    *str;
    int        fd;
    int        i;

    i = 0;
    fd = open("get_next_line.h", O_RDONLY);
    str = get_next_line(fd);
    while (i < 40)
    {
        printf("%s", str);
        if (str)
            free(str);
        str = get_next_line(fd);
        i++;
    }
    close(fd);
}
