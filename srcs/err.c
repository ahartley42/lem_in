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
