/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 06:43:14 by tcoetzee          #+#    #+#             */
/*   Updated: 2020/06/10 14:48:51 by svan-nie         ###   ########.fr       */
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


//test for leaks
char	*fjoin(char *s1, char *s2)
{
	char	*ans;
	char	*tmp;

	ans = NULL;
	if (!s1)
	{
		tmp = ft_strdup(s2);
		ans = ft_strjoin(tmp, "\n");
	}
	else if (line)
	{
		tmp = ft_strjoin(s1, s2);
		ans = ft_strjoin(tmp, "\n");
	}
	free(tmp);
	return (ans);
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
/*
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
*/
			temp = fjoin(temp, line);
		}

	}
	return (validate_map(temp));
}
