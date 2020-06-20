/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 17:22:22 by svan-nie          #+#    #+#             */
/*   Updated: 2020/06/04 17:22:22 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void    free2dArray(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

void	froom(t_room **lst)
{
	char 	*s;
	t_room	**p;

	if ((*lst)->next)
	{
		froom(&((*lst)->next));
	}
	s = (*lst)->name;
	p = (*lst)->path;
	free(s);
	free(p);
	free(*lst);
}

void	free_two_strings(char *s1, char *s2)
{
	free(s1);
	free(s2);
}

// void	ft_putendl_free_exit(char *str, char **map, t_room lem) 
// {
//         int i;

//         i = 0;
//         while (str[i] != '\0')       
//         {
//                 write(1, &str[i], 1);
//                 i++;
//         }
//         write(1, "\n", 1);
//         free2dArray(map);
//         froom(&lem);
//         exit(1);
// }