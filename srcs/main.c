/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 12:05:26 by svan-nie          #+#    #+#             */
/*   Updated: 2020/06/22 12:05:48 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int main(void){
    t_room *lem;
    t_room *tmp;
    char    **map;
    int ant_amount;
	int		i;

    lem = initialize_struct();
    ant_amount = 0;
	i = 0;
    tmp = lem;
    map = read_map();
    ft_strlen_2d_array(map);
    verify_map_and_data(tmp, lem, map, &ant_amount);
	tmp = lem;
	while (!(tmp->type & 2))
		tmp = tmp->next;
	pathfinder(&tmp);
	while (map[i])
	{
		ft_putendl(map[i]);
		i++;
	}
	i = 1;
	while (i < ant_amount + path_size(&tmp))
	{
		print_solution(&tmp, ant_amount, i);
		i++;
	}
    // ft_putendl_free_exit("ERROR", map, lem);
    free2dArray(map);
    froom(&lem);
    return (0);
}
