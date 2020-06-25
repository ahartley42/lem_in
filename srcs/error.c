/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 12:06:37 by svan-nie          #+#    #+#             */
/*   Updated: 2020/06/24 18:24:12 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_check_for_error(unsigned char dip, char **tda, t_room *lem)
{
	if ((dip & 2) == 0 || (dip & 4) == 0)
		err_duo(&lem, tda);
	if ((dip & 8) == 0)
		err_duo(&lem, tda);
	if ((dip & 16) == 0)
		err_duo(&lem, tda);
}

void	ft_wrong_name_error(char *firstName, char *lastName, t_room *lem, \
		char **tda)
{
	t_room	*tmp;
	int     count;
	int     count2;

	tmp = lem;
	count = 0;
	count2 = 0;
	while (tmp)
	{
		if (ft_strequ(firstName, (tmp)->name))
			count++;
		if (ft_strequ(lastName, (tmp)->name))
			count2++;
		tmp = tmp->next;
	}
	if (count < 1 || count2 < 1)
	{
		free_two_strings(firstName, lastName);
		err_duo(&lem, tda);
	}
}
