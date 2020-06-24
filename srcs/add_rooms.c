/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 22:29:41 by svan-nie          #+#    #+#             */
/*   Updated: 2020/06/11 22:29:41 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void    ft_add_rooms(t_room *lem, char **room_data, int *j)
{
    int i;

    i = *j;
    lem->room_id = i;
    i++;
    *j = i;
    lem->name = ft_strdup(room_data[0]);
    lem->xy[0] = ft_atoi(room_data[1]);
    lem->xy[1] = ft_atoi(room_data[2]);
    lem->ant_id = 0;
    lem->run = 0;
    lem->type = 0;
    lem->path = NULL;
    lem->next = NULL;
    lem->next = initialize_struct();
}

void    ft_add_start_room(t_room *lem, char **room_data, int *j)
{
    int i;

    i = *j;
    lem->room_id = i;
    i++;
    *j = i;
    lem->name = ft_strdup(room_data[0]);
    lem->xy[0] = ft_atoi(room_data[1]);
    lem->xy[1] = ft_atoi(room_data[2]);
    lem->ant_id = 0;
    lem->run = 0;
    lem->type = 0;
    lem->type |= 2;
    lem->path = NULL;
    lem->next = NULL;
    lem->next = initialize_struct();
}

void    ft_add_end_room(t_room *lem, char **room_data, int *j)
{
    int i;

    i = *j;
    lem->room_id = i;
    i++;
    *j = i;
    lem->name = ft_strdup(room_data[0]);
    lem->xy[0] = ft_atoi(room_data[1]);
    lem->xy[1] = ft_atoi(room_data[2]);
    lem->ant_id = 0;
    lem->run = 0;
    lem->type = 0;
    lem->type |= 4;
    lem->path = NULL;
    lem->next = NULL;
    lem->next = initialize_struct();
}
