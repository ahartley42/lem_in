/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_modified.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 22:03:48 by svan-nie          #+#    #+#             */
/*   Updated: 2020/06/08 22:03:48 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

// looking for space in ft_strlen if it comes accross L error out
int ft_strlen_space(char *str)
{
    size_t i;
    
    i = 0;

    if(str[i] == 'L')
    {
        ft_putstr("Error: cannot have caps L at the start of the name \n");
        exit(1);
    }
    while(str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            break;
        }
        i++;
    }
    return (i);
}

// looking for space in ft_strlen if it comes accross L or - in a name it will error out
int ft_strlen_space_error(char *str)
{
    size_t i;
    
    i = 0;

    if(str[i] == 'L')
    {
        ft_putstr("Error: cannot have caps L at the start of the name \n");
        exit(1);
    }
    while(str[i] != '\0')
    {
        if (str[i] == '-')
        {
            ft_putstr("Error: cannot have a - in the name \n");
            exit(1);
        }
        if (str[i] == ' ')
        {
            break;
        }
        i++;
    }
    return (i);
}

// counts the amount of spaces if smaller than 2 or bigger than two error
void ft_strlen_space_count(char *str)
{
    int i;
    int k;

    i = 0;
    k = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        k++;
        i++; 
    }
    if (k > 2 || k < 2)
    {
        ft_putstr("Error: Badly Formatted Map, room invalid \n");
        exit(1);
    }
}

// checking to see if there is only 1 '-' in the name else error
int    ft_strlen_pipes(char *str)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    if(str[i] == 'L')
    {
        ft_putstr("Error: cannot have caps L at the start of the name \n");
        exit(1);
    }
    while (str[i] != '\0')
    {
        if (str[i] == '-')
        j++;
        i++;
    }
    if (j != 1){
        ft_putstr("Error: Badly Formatted Map, pipe invalid \n");
        exit(1);
    }
    return (1);
}

// checks to see if the pipes are in the correct order it will only skip through comments if anthing else in under the pipes it will display error
void    ft_strlen_2d_array(char **str)
{
    int i;
    int k;
    int trackHyphen;

    i = 0;
    k = 0;
    trackHyphen = 0;
    while (str[i])
    {
        while (str[i][k])
        {
            if (str[i][k] == '-'){
                trackHyphen++;
                break;
            }
            k++;
        }
        if (trackHyphen == 1)
        break;
        k = 0;
        i++;
    }
    trackHyphen = 0;
    while (str[i])
    {
        while (str[i][k])
        {
            if (str[i][k] == '-')
            trackHyphen++;
            if (str[i][0] == '#' && (str[i][1] != '#' || str[i][1] == '\0'))
            trackHyphen++;
            k++;
        }
        if (trackHyphen == 0)
        {
            ft_putstr("Error: Badly Formatted Map with pipes \n");
            exit(1);
        }else
        trackHyphen = 0;
        k = 0;
        i++;
    }
}