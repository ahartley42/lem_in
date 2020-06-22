#include "../includes/lem_in.h"
#include <stdio.h>

int main(void){
    t_room *lem;
    t_room *tmp;
    char    **map;
    int ant_amount;
	int		i;

    lem = initialize_struct();
    ant_amount = 0;
	i = 1;
    tmp = lem;
    map = read_map();
    ft_strlen_2d_array(map);
    verify_map_and_data(tmp, lem, map, &ant_amount);
	tmp = lem;
	while (!(tmp->type & 2))
		tmp = tmp->next;
	pathfinder(&tmp);
	while (i <= ant_amount + path_size(&tmp))
	{
		print_solution(&tmp, ant_amount, i);
		i++;
	}
    // ft_putendl_free_exit("ERROR", map, lem);
    printf("%d", ant_amount);
    free2dArray(map);
    froom(&lem);
    return (0);
}
