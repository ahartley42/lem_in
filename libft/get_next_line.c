/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 05:53:36 by tcoetzee          #+#    #+#             */
/*   Updated: 2020/06/10 11:53:44 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int push_to_line(int ret, int fd, char **s, char **line)
{
    int     length;
    char    *temp;
    if (ret < 0)
	{
		ft_strdel(&s[fd]);
        return (-1);
	}
    else if (ret == 0 && s[fd] == NULL)
        return (0);
    else
    {
        length = 0;
        while (s[fd][length] != '\0' && s[fd][length] != '\n')
            length++;
        if (s[fd][length] == '\n')
        {
			if (s[fd][length + 1] == '\n')
			{
				ft_strdel(&s[fd]);
				return (-1);
			}
            *line = ft_strsub(s[fd], 0, length);
            temp = ft_strdup(&(s[fd][length + 1]));
            free(s[fd]);
            s[fd] = temp;
            if (s[fd][0] == '\0')
                ft_strdel(&s[fd]);
        }
        else
        {
            *line = ft_strdup(s[fd]);
            ft_strdel(&s[fd]);
        }
        return (1);
    }
}

int get_next_line(const int fd, char **line)
{
    static char *s[255];
    char        buf[BUFF_SIZE + 1];
    char        *temp;
    int         ret;
	int			nl;

    ret = 0;
	nl = 0;
    if (fd < 0 || line == NULL)
        return (-1);
    while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
    {
        buf[ret] = '\0';
        if (s[fd] == NULL)
            s[fd] = ft_strdup(buf);
        else
        {
            temp = ft_strjoin(s[fd], buf);
            free(s[fd]);
            s[fd] = temp;
        }
        if (ft_strchr(buf, '\n'))
            break;
    }
    return (push_to_line(ret, fd, s, line));
}
