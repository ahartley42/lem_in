/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 18:44:50 by svan-nie          #+#    #+#             */
/*   Updated: 2020/06/11 18:44:50 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/lem_in.h"

t_room *initialize_struct()//initialize 
{
    t_room *lem;

    lem = (t_room *)malloc(sizeof(*lem));
    lem->room_id = 0;
    lem->ant_id = 0;
    lem->run = 0;
    lem->xy[0] = 0;
    lem->xy[1] = 0;
    lem->name = NULL;
    lem->type = 0;
    lem->path = NULL;
    lem->next = NULL;
    return (lem);
}