/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map_functions_two.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 16:25:18 by svan-nie          #+#    #+#             */
/*   Updated: 2020/06/21 16:25:18 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_check_address_exists(char *firstName, char *lastName, t_room *lem)
{
	t_room *tmp;
	t_room *tmp2;

	tmp = lem;
	tmp2 = lem;
	while (tmp && !(ft_strequ(firstName, (tmp)->name)))
		tmp = tmp->next;
	while (tmp2 && !(ft_strequ(lastName, (tmp2)->name)))
		tmp2 = tmp2->next;
	if (ft_strequ(lastName, (tmp)->name) && ft_strequ(lastName, (tmp2)->name))
		return (0);
	return (1);
}

void    check_x_and_y(t_room *lem, char **tda, char *firstName, char *lastName)
{
	t_room *tmp;
	t_room *tmp2;

	tmp = lem;
	tmp2 = lem;
	while ((tmp) != NULL)
	{
		tmp2 = tmp2->next;
		while (tmp2 && tmp2->next)
		{
			if (tmp->xy[0] == tmp2->xy[0] && tmp->xy[1] == tmp2->xy[1])
			{
				free_two_strings(firstName, lastName);
				err_duo(&lem, tda);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
		if ((tmp) != NULL)
			tmp2 = tmp;
	}
}

void    ft_add_pipe_address(t_room *lem, char **tda, int *i)
{
	t_room	*tmp;
	t_room	*tmp2;
	char    *firstName;
	char    *lastName;
	int		j;

	j = *i;
	while (tda[j])
	{
		if (tda[j][0] != '#')
		{
			tmp = lem;
			tmp2 = lem;
			firstName = ft_find_firstName(tda, &j);
			lastName = ft_find_lastName(tda, &j);
			check_x_and_y(lem, tda, firstName, lastName);
			ft_wrong_name_error(firstName, lastName, lem, tda);
			if (ft_check_address_exists(firstName, lastName, lem) == 1)
			{
				while (tmp && !(ft_strequ(firstName, (tmp)->name)))
					tmp = tmp->next;
				while (tmp2 && !(ft_strequ(lastName, (tmp2)->name)))
					tmp2 = tmp2->next;
				rpush(&tmp, tmp2);
				rpush(&tmp2, tmp);
			}
			free_two_strings(firstName, lastName);
		}
		j++;
	}
}
