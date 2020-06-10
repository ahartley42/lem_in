  
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 06:43:14 by tcoetzee          #+#    #+#             */
/*   Updated: 2020/06/10 02:55:01 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char **validate_map(char *array)
{
    char **dblarray;
    if (array == NULL)
    {
        ft_putendl("ERROR");
        exit(1);
    }
    dblarray = ft_strsplit(array, '\n');
    if (dblarray == NULL)
    {
        ft_putendl("ERROR");
        exit(1);
    }
    return (dblarray);
}

char **read_map()
{
    int     fd;
    int     ret;
    char    *line;
    char    *temp;

    fd = STDIN_FILENO;
    ret = 1;
    temp = NULL;
    while (ret == 1)
    {
        ret = get_next_line(fd, &line);
        if (ret == 1 || ret == 0)
        {

            if (temp == NULL)
            {
                temp = ft_strdup(line);
                temp = ft_strjoin(temp, "\n");
            }
            else if (line != NULL)
            {
                temp = ft_strjoin(temp, line);
                temp = ft_strjoin(temp, "\n");
            }
            else
                ft_strdel(&temp);
        }

    }
    return (validate_map(temp));
}