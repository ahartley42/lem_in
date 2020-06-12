#include "../includes/lem_in.h"

void	rpop(t_room ***path, int i)
{
	while ((*path)[i + 1])
	{
		(*path)[i] = (*path)[i + 1];
		i++;
	}
	(*path)[i] = NULL;
}

unsigned char	pathfinder(t_room **room, unsigned char e)
{
	int	i;

	i = 0;
	(*room)->type |= 1;
	if ((*room)->type & 4)
		ending(); //algo needed
	else
	{
		while ((*room)->path[i])
		{
			if (!((*room)->path[i]->type & 1) && !((*room)->path[i]->type & 2))
			{
				e = pathfinder(&((*room)->path[i]), e);
				error(e);
			}
			i++;
		}
	}
	(*room)->type ^= 1;
	return (e);
}

//
