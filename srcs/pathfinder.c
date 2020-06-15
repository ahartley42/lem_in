#include "../includes/lem_in.h"

void	rpop(t_room **room, int i)
{
	while ((*room)->path[i + 1])
	{
		(*room)->path[i] = (*room)->path[i + 1];
		i++;
	}
	(*room)->path[i] = NULL;
}

void	rpush(t_room **room, t_room *add)
{
	int	i;
	int j;
	t_room **new;

	i = 0;
	j = 0;
	if ((*room)->path)
	{
		while ((*room)->path[i])
			i++;
	}
	new = (t_room **)malloc(sizeof(t_room **) * (i + 2));
	while (j < i)
	{
		new[j] = (*room)->path[j];
		j++;
	}
	new[j] = add;
	new[j + 1] = NULL;
	free((*room)->path);
	(*room)->path = new;
}

/*
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
*/
//
