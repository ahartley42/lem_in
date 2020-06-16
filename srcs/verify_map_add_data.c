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
    }
    return (0);
}

// keeping track if two starts or ends
void ft_keep_track_start_end(int total,int *start,int *end,int *isStart,int *isEnd)
{
    int st;
    int ed;
    st = *start; // keeping track how many start and ends it finds
    ed = *end;
    if (total == 0)
    {
        st++;
        *start = st;
        *isStart = st;
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
        *isEnd = ed;
        if (ed == 2)
        {
            ft_putstr("Error: two ends error Program Exit\n");
            exit(1);
        }
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

    // going to go through all the (tmp)->path to see if the room all ready exists inside if it does it will just skip it
// int ft_check_address_exists(char *firstName, char *lastName, t_room *lem_head)
// {
//     t_room *tmp;
//     t_room *tmp2;
//     int i;
//     int count;
//     int count2;

//     tmp = lem_head;
//     tmp2 = lem_head;
//     i = 0;
//     count = 0;
//     count2 = 0;
//     printf("before tmp: %s \n", (tmp)->name);
//     printf("before tmp2: %s \n", (tmp2)->name);
//     while ((tmp) != NULL)
//     {
//         if (ft_strequ(firstName, (tmp)->name))
//             break;
//         tmp = tmp->next;
//     }
//     while ((tmp2) != NULL)
//     {
//         if (ft_strequ(lastName, (tmp2)->name))
//             break;
//         tmp2 = tmp2->next;
//     }
//     printf("tmp: %s \n", (tmp)->name);
//     printf("tmp2: %s \n", (tmp2)->name);
//     if ((tmp)->path != NULL)
//     {
//     while ((tmp)->path[i] != NULL)
//     {
//         if (ft_strequ(lastName, tmp->path[i]->name))
//         {
//             count++;
//             break;
//         }
//         i++;
    
//     }
//     }
//     i = 0;
//         if ((tmp)->path != NULL)
//     {
//     while ((tmp2)->path[i] != NULL)
//     {
//         if (ft_strequ(firstName, tmp2->path[i]->name))
//         {
//             count2++;
//             break;
//         }
//         i++;
//     }
//     }
//     printf("count %d \n", count);
//     printf("count2 %d \n", count2);
//     if(count > 0 && count2 > 0)
//     return (0);
//     return (1);
// }

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
    printf("%s \n", tmp->name);
    printf("%s \n", tmp2->name);
    while (twodarray[j])
    {
        firstName = ft_find_firstName(twodarray, &j);
        lastName = ft_find_lastName(twodarray, &j);
        if (twodarray[j][0] != '#')
        {
            ft_wrong_name_error(firstName, lastName, lem_head);
            // if (ft_check_address_exists(firstName, lastName, lem_head) == 1){ // working on this function
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
            printf("i was here \n");
            // }
        }
        j++;
        free_two_strings(firstName, lastName);
    }
}

void    verify_map_and_data(t_room *lem_tmp, t_room *lem_head, char **twodarray, int *ant_amount)
{
    // char    nameTrack[] = "";
    int     i;
    int     j;
    int     start;  // will be removed for struct
    int     end;    // will be removed for struct
    int     total;
    int     strlen;
    int     strlenpipe;
    int     pipeTrack;
    int     roomTrack;
    int     isStart;
    int     isEnd;

    i = 0;
    j = 0;
    start = 0;
    end = 0;
    total = 0;
    strlen = 0;
    strlenpipe = 0;
    pipeTrack = 0;
    roomTrack = 0;
    isStart = 0;
    isEnd = 0;
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
            ft_keep_track_start_end(total, &start, &end, &isStart, &isEnd);
            // ft_add_Command_rooms(twodarray[i + 1], total);
            if (isStart == 1)
            {
                isStart++;
                i++;
                while (twodarray[i][0] == '#' && (twodarray[i][1] != '#' || twodarray[i][1] == '\0'))
                i++;
                while (twodarray[i][0] == '#' && twodarray[i][1] == '#')
                i++;
                if ((strlen = ft_strlen_space(twodarray[i])) && twodarray[i][strlen] == ' ' && twodarray[i][strlen + 1])
                {
                }
                else{
                ft_putendl("Error: starting room invalid");
                exit(1);
                }
            }
            if (isEnd == 1)
            {
                isEnd++;
                i++;
                while (twodarray[i][0] == '#' && (twodarray[i][1] != '#' || twodarray[i][1] == '\0'))
                i++;
                while (twodarray[i][0] == '#' && twodarray[i][1] == '#')
                i++;
                if ((strlen = ft_strlen_space(twodarray[i])) && twodarray[i][strlen] == ' ' && twodarray[i][strlen + 1])
                {
                }
                else{
                ft_putendl("Error: ending room invalid");
                exit(1);
                }
            }
        }
        if ((strlen = ft_strlen_space(twodarray[i])) && twodarray[i][strlen] == ' ' && twodarray[i][strlen + 1]){ // checks for room valid
            char    **check_rooms;
            ft_strlen_space_count(twodarray[i]); // counting the amount of spaces more or less than 2 displays error
            check_rooms = ft_strsplit(twodarray[i], ' ');
            ft_strlen_space_error(check_rooms[0]); // checks for name starting with L and - inside the name
            if (check_int(check_rooms[1]) == 1 && check_int(check_rooms[2]) == 1)
            {
                if (isStart == 1){
                    ft_putstr("Correct room \n");
                    ft_add_start_room(lem_tmp, check_rooms, &j);
                    lem_tmp = lem_tmp->next;
                }else if (isEnd == 1)
                {
                    ft_putstr("Correct room \n");
                    ft_add_end_room(lem_tmp, check_rooms, &j);
                    lem_tmp = lem_tmp->next;
                }else
                {
                    ft_putstr("Correct room \n");
                    ft_add_rooms(lem_tmp, check_rooms, &j);
                    lem_tmp = lem_tmp->next;
                }
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
                // ft_strlen_name_hold(*lem_head, twodarray, &i);
                ft_putstr("Correct pipe \n");
                ft_add_pipe_address(lem_head, twodarray, &i);
            }
            else{
                ft_putstr("Error: Invalid Pipe \n");
            }
            pipeTrack++;
        }
        i++;
        strlen = 0;
    }
    ft_check_for_error(&start, &end, &pipeTrack, &roomTrack); //saving lines checks to see if end and start < 1 or if pipeTrack and roomTrack is < 1
}