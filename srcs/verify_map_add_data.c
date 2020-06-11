/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map_add_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 22:26:16 by svan-nie          #+#    #+#             */
/*   Updated: 2020/06/08 22:26:16 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <stdio.h> // remove

int    ft_check_start_end(char *twodarray)
{
     if (ft_strequ(twodarray, "##start"))
    {
        return (0);
    }
    else if (ft_strequ(twodarray, "##end"))
    {
        return (1);
    }else // will have to remove
    {
        ft_putstr("Error: no known command");
        return (-1);
    }
}

// keeping track if two starts or ends
void ft_keep_track_start_end(int total,int *start,int *end)
{
    int st;
    int ed;
    st = *start; // keeping track how many start and ends it finds
    ed = *end;
    if (total == 0)
    {
        st++;
        *start = st;
        if (st == 2)
        {
            ft_putstr("Error: two starts error Program Exit\n");
            exit(1);
        }
    }
    if (total == 1)
    {
        ed++;
        *end = ed;
        if (ed == 2)
        {
            ft_putstr("Error: two ends error Program Exit\n");
            exit(1);
        }
    }
}

void verify_map_and_data(t_room *lem, char **twodarray, int *ant_amount)
{
    // char    nameTrack[] = "";
    int     i;
    int     start;  // will be removed for struct
    int     end;    // will be removed for struct
    int     total;
    int     strlen;
    int     strlenpipe;
    int     pipeTrack;
    int     roomTrack;

    lem->room_id = 1; // remove because lem not been used yet
    // nameTrack = "wee";
    // printf("%s", nameTrack);
    i = 0;
    start = 0;
    end = 0;
    total = 0;
    strlen = 0;
    strlenpipe = 0;
    pipeTrack = 0;
    roomTrack = 0;
    // i = ft_check_ants_and_skip_comments_on_top(**twodarray, &ant_amount); // not working right now

    // looking for ant_amount once found breaks out and returns ant amount  if not found returns error
    while (twodarray[i])
    {
        i++;
    }
    if (i < 2)
    {
        ft_putstr("Error: wrong \n");
        exit(1);
    }
    i = 0;
    while (twodarray[i])
    {
        if (twodarray[i][0] == '#') {
            if (ft_strequ(twodarray[i], "##start") || ft_strequ(twodarray[i], "##end")){

            }
            else{
                i++;
            }
        }
        if (check_int(twodarray[i]) == 1)
        {
            *ant_amount = ft_check_ants(twodarray[i]);
            break;
        }
        i++;
    }
    if (*ant_amount == 0)
    {
        ft_putstr("Error: please enter ant's\n");
        exit(1);
    }
    i++; // incrementing past the ant_amount
    while (twodarray[i])
    {
        if (twodarray[i][0] == '#' && twodarray[i][1] != '#'){ // checks for comment
        i++;
        }
        if (check_int(twodarray[i]) == 1) // checks to see if more than one ant
        {
            ft_putstr("Error: Badly Formatted Map \n");
            exit(1);
        }
        if (twodarray[i][0] == '#' && twodarray[i][1] == '#') // checks for start and end
        {
            total = ft_check_start_end(twodarray[i]);
            ft_keep_track_start_end(total, &start, &end);
            // ft_add_Command_rooms(twodarray[i + 1], total);
        }
        if ((strlen = ft_strlen_space(twodarray[i])) && twodarray[i][strlen] == ' ' && twodarray[i][strlen + 1]){ // checks for room valid
            char    **check_rooms;
            ft_strlen_space_count(twodarray[i]); // counting the amount of spaces more or less than 2 displays error
            check_rooms = ft_strsplit(twodarray[i], ' ');
            ft_strlen_space_error(check_rooms[0]); // checks for name starting with L and - inside the name
            printf("what inside: %s", check_rooms[0]);
            if (check_int(check_rooms[1]) == 1 && check_int(check_rooms[2]) == 1)
            {
                ft_putstr("Correct room \n");
                printf("whats inside: %s \n", check_rooms[0]);
            }else
            {
                ft_putstr("Error: Badly Formatted Map X Y not integer \n");
                exit(1);
            }
            roomTrack++;
            free2dArray(check_rooms);
        }
        if ((strlenpipe = ft_strlen_space(twodarray[i])) && twodarray[i][strlenpipe] == '\0' && twodarray[i][0] != '#') // checks to see if pipes is valid
        {
            strlenpipe = 0;
            printf("pipe: %s \n",twodarray[i]);
            if (( strlenpipe = ft_strlen_pipes(twodarray[i])) == 1)
            {
                ft_putstr("Correct pipe \n");
            }
            else{
                ft_putstr("Error: Invalid Pipe \n");
            }
            pipeTrack++;
        }
        i++;
        strlen = 0;
    }
    if (start < 1 || end < 1)
    {
        ft_putstr("Error: Badly Formatted Map no start or end \n");
        exit(1);
    }
    if (pipeTrack < 1)
    {
        ft_putstr("Error: Badly Formatted no Pipes \n");
        exit(1);
    }
    if (roomTrack < 1)
    {
        ft_putstr("Error: Badly Formatted no rooms \n");
        exit(1);
    }
}