/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map_functions_one.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 16:23:49 by svan-nie          #+#    #+#             */
/*   Updated: 2020/06/21 16:23:49 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int    ft_check_start_end(char *twodarray)
{
     if (ft_strequ(twodarray, "##start"))
    {
        return (0);
    }
    else if (ft_strequ(twodarray, "##end"))
    {
        return (1);
    }
    return (2);
}

void ft_keep_track_start_end(int total, unsigned char *dip_Switch)
{
    if (total == 0)
    {
        if ((*dip_Switch & 2) == 2)
        {
            ft_putstr("Error: two starts error Program Exit\n");
            exit(1);
        }
        *dip_Switch |= 32;
        if ((*dip_Switch & 2) == 0)
        *dip_Switch |= 2;
    }
    if (total == 1)
    {
        if ((*dip_Switch & 4) == 4)
        {
            ft_putstr("Error: two ends error Program Exit\n");
            exit(1);
        }
        *dip_Switch |= 64;
        if ((*dip_Switch & 4) == 0)
        *dip_Switch |= 4;
    }
}

char    *ft_find_firstName(char **twodarray, int *i)
{
    char    *firstName;
    int     len;
    int     j;

    len = 0;
    j = *i;
    len = ft_strlen_hyphen(twodarray, i);
    firstName = ft_strnew(len);
    ft_strcpy_to_hyphen(firstName, twodarray[j], '-');
    return (firstName);
}

char    *ft_find_lastName(char **twodarray, int *i)
{
    char    *lastName;
    int     len;
    int     len2;
    int     j;

    len = 0;
    j = *i;
    len = ft_strlen_hyphen(twodarray, i);
    len2 = ft_strlen_till_end(twodarray, i, &len);
    lastName = ft_strnew(len2);
    ft_strcpy_after_hyphen(lastName, twodarray[j], '-');
    return (lastName);
}

/*
** line 28
** keeping track if two starts or ends
*/