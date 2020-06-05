#include "../includes/lem_in.h"
#include "../libft/libft.h"

void	init(t_room *list, char *name, char **path)
{
	int	i;

	i = 0;
	(*list)->room_id = 0; //
	(*list)->ant_id = 0;
	(*list)->run = 0;
	(*list)->xy[0] = 0; //
	(*list)->xy[1] = 0; //
	(*list)->name = name;
	(*list)->type = 0;
	while (path[i])
	{
		(*list)->next[i] = path[i];
		i++;
	}
}
