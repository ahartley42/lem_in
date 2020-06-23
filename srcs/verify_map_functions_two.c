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

int ft_check_address_exists(char *firstName, char *lastName, t_room *lem_head)
{
    t_room *tmp;
    t_room *tmp2;
    int i;
    int count;
    int count2;

    tmp = lem_head;
    tmp2 = lem_head;
    i = 0;
    count = 0;
    count2 = 0;
    while ((tmp) != NULL)
    {
        if (ft_strequ(firstName, (tmp)->name))
            break;
        tmp = tmp->next;
    }
    while ((tmp2) != NULL)
    {
        if (ft_strequ(lastName, (tmp2)->name))
            break;
        tmp2 = tmp2->next;
    }
    if ((tmp)->path != NULL)
    {
    while ((tmp)->path[i] != NULL)
    {
        if (ft_strequ(lastName, tmp->path[i]->name))
        {
            count++;
            break;
        }
        i++;
    }
    }
    i = 0;
    if ((tmp2)->path != NULL)
    {
    while ((tmp2)->path[i] != NULL)
    {
        if (ft_strequ(firstName, tmp2->path[i]->name))
        {
            count2++;
            break;
        }
        i++;
    }
    }
    if(count > 0 && count2 > 0)
    return (0);
    return (1);
}

void    check_x_and_y(t_room *lem_head, char **twodarray, char *firstName, char *lastName)
{
    t_room *tmp;
    t_room *tmp2;

    tmp = lem_head;
    tmp2 = lem_head;
    while ((tmp) != NULL)
    {
        tmp2 = tmp2->next;
        while ((tmp2) != NULL)
        {
            while ((tmp2) != NULL)
            {
                if (tmp->xy[0] == tmp2->xy[0] && tmp->xy[1] == tmp2->xy[1])
                {
                    free_two_strings(firstName, lastName);
                    err_duo(&lem_head, twodarray);
                }
                tmp2 = tmp2->next;
            }
        }
        tmp = tmp->next;
        if ((tmp) != NULL)
        tmp2 = tmp;
    }
}

void    ft_add_pipe_address(t_room *lem_head,char **twodarray, int *i)
{
    t_room *tmp;
    t_room *tmp2;
    char    *firstName;
    char    *lastName;
    int j;

    tmp = lem_head;
    tmp2 = lem_head;
    j = *i;
    while (twodarray[j])
    {
        firstName = ft_find_firstName(twodarray, &j);
        lastName = ft_find_lastName(twodarray, &j);
        if (twodarray[j][0] != '#')
        {
            check_x_and_y(lem_head, twodarray, firstName, lastName);
            ft_wrong_name_error(firstName, lastName, lem_head, twodarray);
            if (ft_check_address_exists(firstName, lastName, lem_head) == 1){
            while ((tmp) != NULL)
            {
             if (ft_strequ(firstName, (tmp)->name))
             break;
                tmp = tmp->next;
            }
            while ((tmp2) != NULL)
            {
                if (ft_strequ(lastName, (tmp2)->name))
                break;
                tmp2 = tmp2->next;
            }
            rpush(&tmp, tmp2);
            rpush(&tmp2, tmp);
            tmp = lem_head;
            tmp2 = lem_head;
            }
        }
        j++;
        free_two_strings(firstName, lastName);
    }
}

/*
** line 15
** going to go through all the (tmp)->path to see if the room all ready exists inside if it does it will just skip it
** working on this function
*/