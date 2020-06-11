/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 06:43:14 by tcoetzee          #+#    #+#             */
/*   Updated: 2020/06/11 13:40:31 by svan-nie         ###   ########.fr       */
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
    free(array);
	return (dblarray);
}


//test for leaks
char	*fjoin(char *s1, char *s2)
{
	char	*ans;
	char	*tmp;

	tmp = NULL;
	ans = NULL;
	if (!s1)
	{
		tmp = ft_strdup(s2);
		ans = ft_strjoin(tmp, "\n");
	}
	else if (s2)
	{
		tmp = ft_strjoin(s1, s2);
        free(s1);
		ans = ft_strjoin(tmp, "\n");
	}
	free(tmp);
	return (ans);
}

char **read_map()
{
	int     ret;
	char    *line;
	char    *temp;

	temp = NULL;
	while ((ret = get_next_line(0, &line) == 1))
	{
			temp = fjoin(temp, line);
			free(line);
	}
	return (validate_map(temp));
}
