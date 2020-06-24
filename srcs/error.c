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

void	error(unsigned char e)
{
	if (e)
	{
		write(1, "\e[31mERROR\n\e[0m", 15);
		exit(1);
	}
}

// checks to see if start and end, and checks to see if it has enterd pipes and rooms
void ft_check_for_error(unsigned char dip_Switch, char **twodarray, t_room *lem_head)
{
    if ((dip_Switch & 2) == 0 || (dip_Switch & 4) == 0)
    {
        err_duo(&lem_head, twodarray);
    }
    if ((dip_Switch & 8) == 0)
    {
        err_duo(&lem_head, twodarray);
    }
    if ((dip_Switch & 16) == 0)
    {
        err_duo(&lem_head, twodarray);
    }
}

// checking to see if the name passed in pipes exist and is not fake
void ft_wrong_name_error(char *firstName, char *lastName, t_room *lem_head, char **twodarray)
{
    t_room *tmp;
    int     count;
    int     count2;

    tmp = lem_head;
    count = 0;
    count2 = 0;
    while ((tmp) != NULL)
    {
		// if (ft_strequ(firstName, "#"))
        // count++;
        if (ft_strequ(firstName, (tmp)->name))
        count++;
        if (ft_strequ(lastName, (tmp)->name))
        count2++;
        tmp = tmp->next;
    }
    if (count < 1)
    {
        free_two_strings(firstName, lastName);
        err_duo(&lem_head, twodarray);
    }
    if (count2 < 1)
    {
        free_two_strings(firstName, lastName);
        err_duo(&lem_head, twodarray);
    }
}