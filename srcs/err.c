/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 22:36:38 by svan-nie          #+#    #+#             */
/*   Updated: 2020/06/23 22:36:39 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	err_map(char **map)
{
	free2dArray(map);
	ft_putendl("\e[31mERROR\e[0m");
	exit(1);
}

void	err_room(t_room **room)
{
	froom(room);
	ft_putendl("\e[31mERROR\e[0m");
	exit(1);
}

void	err_duo(t_room **room, char **map)
{
	free2dArray(map);
	froom(room);
	ft_putendl("\e[31mERROR\e[0m");
	exit(1);
}
