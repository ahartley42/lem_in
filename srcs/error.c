/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 12:06:37 by svan-nie          #+#    #+#             */
/*   Updated: 2020/06/22 18:42:01 by svan-nie         ###   ########.fr       */
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
void ft_check_for_error(unsigned char dip_Switch)
{
    if ((dip_Switch & 2) == 0 || (dip_Switch & 4) == 0)
    {
        ft_putstr("Error: Badly Formatted Map no start or end \n");
        exit(1);   
    }
    if ((dip_Switch & 8) == 0)
    {
        ft_putstr("Error: Badly Formatted no Pipes \n");
        exit(1);
    }
    if ((dip_Switch & 16) == 0)
    {
        ft_putstr("Error: Badly Formatted no rooms \n");
        exit(1);
    }
}

// checking to see if the name passed in pipes exist and is not fake
void ft_wrong_name_error(char *firstName, char *lastName, t_room *lem_head)
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
        ft_putendl("ERROR: room name does not exist");
        exit(1);
    }
    if (count2 < 1)
    {
        ft_putendl("ERROR: room name does not exist");
        exit(1);
    }
}