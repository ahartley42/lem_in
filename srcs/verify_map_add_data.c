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

// void    ft_add_rooms(t_room *lem, char **room_data)
// {
//     int i;

//     i = 0;
//     lem->room_id = i;
//     i++;
//     lem->name = ft_strdup(room_data[0]);
//     lem->xy[0] = ft_atoi(room_data[1]);
//     lem->xy[1] = ft_atoi(room_data[2]);
//     lem->ant_id = 0;
//     lem->run = 0;
//     lem->type = 0;
//     lem->path = NULL;
//     lem->next = NULL;
//     lem->next = initialize_struct();
// }

void ft_check_for_error(int *start, int *end, int *pipeTrack, int *roomTrack)
{
        if (*start < 1 || *end < 1)
    {
        ft_putstr("Error: Badly Formatted Map no start or end \n");
        exit(1);
    }
    if (*pipeTrack < 1)
    {
        ft_putstr("Error: Badly Formatted no Pipes \n");
        exit(1);
    }
    if (*roomTrack < 1)
    {
        ft_putstr("Error: Badly Formatted no rooms \n");
        exit(1);
    }
}

int ft_strlen_hyphen(char **twodarray,int *i)
{
    int len;
    int j;
    j = *i;
    len = 0;

    while (twodarray[j][len] != '-')
    {
        len++;
    }
    return (len);
}

char	*ft_strcpy_to_hyphen(char *dest, const char *src, char n)
{
	int count;

	count = 0;
	while (src[count] != '\0' && src[count] != n)
	{
		dest[count] = src[count];
		count++;
	}
    dest[count] = '\0';
	return (dest);
}

char	*ft_strcpy_after_hyphen(char *dest, const char *src, char n)
{
	int count;
    int count2;

	count = 0;
    count2 = 0;
    while (src[count] != n)
    count++;
    count++;
	while (src[count] != '\0')
	{
		dest[count2] = src[count];
		count++;
        count2++;
	}
    dest[count2] = '\0';
	return (dest);
}

int    ft_strlen_till_end(char **twodarray, int *i, int *len)
{
    int j;
    int length;
    int len2;

    j = *i;
    length = *len;
    len2 = 0;
    length++;
    while (twodarray[j][length] != '\0')
    {
        len2++;
        length++;
    }
    return (len2);
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

// void    ft_malloc_path(t_room tmp,char *firstName,char *lastName)
// {
//     t_room *temp;
//     int count;
//     int count2;
//     // int lastCount;

//     temp = &tmp;
//     count = 0;
//     count2 = 0;
//     // lastCount = 0;
//     // printf("here \n");
//     // printf("%s \n", firstName);
//     // printf("%s \n", lastName);
//     // while((temp) != NULL)
// 	// {
//     //     printf("room_id: %d \n", (temp)->room_id);
// 	// 	printf("name: %s \n", (temp)->name);
//     //     temp = temp->next;
// 	// }


//     // while ((temp) != NULL)
//     // {
//     //     if (ft_strequ(firstName, (temp)->name))
//     //     {
//     //         // printf("struct: %s \n", (temp)->name);
//     //         // printf("firstName_inside: %s \n", firstName);
//     //         count++;
//     //         // printf("count: %d \n", count);
//     //     }
//     //     if (ft_strequ(lastName, (temp)->name))
//     //     {
//     //         // printf("struct: %s \n", (temp)->name);
//     //         // printf("lastName_inside: %s \n", lastName);
//     //         count2++;
//     //         // printf("count: %d \n", count);
//     //     }
//     //     if (ft_strequ(firstName, (temp)->name) && ft_strequ(lastName, (temp)->name))
//     //     {
//     //         ft_putendl("ERROR");
//     //         exit(1);
//     //     }
//     //     printf("struct: %s \n", (temp)->name);
//     //     temp = temp->next;
//     // }
//     // if (count < 1 || count2 < 1)
//     // {
//     //     ft_putendl("ERROR: name of pipe does not exist");
//     //     exit(1);
//     // }
//     // printf("count: %d \n", count);
//     // printf("count: %d \n", count2);
// }

// void    ft_strlen_name_hold(t_room lem_head ,char **twodarray , int *i)
// {
//     t_room *tmp;
//     char    *firstName;
//     char    *lastName;
//     char    *first2nd;
//     char    *last2nd;
//     int     strlenpipe;
//     // int     len;
//     // int     len2;
//     int     j;
//     int     k;

//     tmp = &lem_head;
//     j = *i;
//     k = *i;
//     strlenpipe = 0;
//     // len = 0;
//     // len2 = 0;
//     // len = ft_strlen_hyphen(twodarray, i);
//     // firstName = ft_strnew(len);
//     // ft_strcpy_to_hyphen(firstName, twodarray[j], '-');
//     // printf("firstName:%s \n", firstName);
//     ///////////////////////////////////////////////////////////////////
//     // len2 = ft_strlen_till_end(twodarray, i, &len);
//     // lastName = ft_strnew(len2);
//     // ft_strcpy_after_hyphen(lastName, twodarray[j], '-');
//     // printf("lastName:%s\n", lastName);
//     ////////////////////////////////////////////////////////////////////
//     int count = 0;
//     int count2 = 0;
//     while (twodarray[j])
//     {
//         firstName = ft_find_firstName(twodarray, &j);
//         lastName = ft_find_lastName(twodarray, &j);
//     // will be using this
//         if ((strlenpipe = ft_strlen_pipes(twodarray[j])) == 1)
//         {
//             // ft_malloc_path(*tmp, firstName, lastName);
//             printf("array: %s \n",twodarray[j]);
//             // tmp = &lem_head;
//             while (twodarray[k])
//             {
//                 first2nd = ft_find_firstName(twodarray, &k);
//                 last2nd = ft_find_lastName(twodarray, &k);
//                 if (firstName == first2nd)
//                 count++;
//                 if (lastName == last2nd)
//                 count2++;
//                 free_two_strings(first2nd, last2nd);
//             }
//             k = *i;
//             while (twodarray[k])
//             {
//                 if (firstName == last2nd)
//                 count++;
//                 if (lastName == firstName)
//                 count++;
//             }
//             k = *i;
//         }
//         printf("next round \n");
//         j++;
//         free_two_strings(firstName, lastName);
//     }
//         // tmp = lem;
//         // going to be useing this
//     // 	while((tmp) != NULL)
// 	// {
//     //     printf("room_id: %d \n", (tmp)->room_id);
// 	// 	printf("name: %s \n", (tmp)->name);
//     //     tmp = tmp->next;
// 	// }
//     // free(firstName);
//     // free(lastName);
// }

void ft_wrong_name(char *firstName, char *lastName, t_room *lem_head)
{
    t_room *tmp;
    int     count;
    int     count2;

    tmp = lem_head;
    count = 0;
    count2 = 0;
    while ((tmp) != NULL)
    {
        if (ft_strequ(firstName, (tmp)->name))
        count++;
        if (ft_strequ(lastName, (tmp)->name))
        count2++;
        tmp = tmp->next;
    }
    if (count < 1)
    {
        ft_putendl("ERROR: name does not exist");
        exit(1);
    }
    if (count2 < 1)
    {
        ft_putendl("ERROR: name does not exist");
        exit(1);
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
    printf("%s \n", tmp->name);
    printf("%s \n", tmp2->name);
    while (twodarray[j])
    {
        firstName = ft_find_firstName(twodarray, &j);
        lastName = ft_find_lastName(twodarray, &j);
        ft_wrong_name(firstName, lastName, lem_head);
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
        j++;
        free_two_strings(firstName, lastName);
    }
}

void verify_map_and_data(t_room *lem_tmp, t_room *lem_head, char **twodarray, int *ant_amount)
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

    // lem->room_id = 1; // remove because lem not been used yet
    // lem->next = initialize_struct();
    // lem->next->room_id = 2;
    // nameTrack = "wee";
    // printf("%s", nameTrack);
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