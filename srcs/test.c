#include "../includes/lem_in.h"
#include <stdio.h>

/*
** typedef struct		s_room
** {
**	int					room_id;
**	int					ant_id;
**	int					run;
**	int					xy[2];
**	char				*name;
**	unsigned char		type;
**	struct s_room		**path;
**	struct s_room		*next;
** }					t_room;
*/

t_room	*add(char *name, int *xy, int id, unsigned char type)
{
	t_room *room;
	
	room = (t_room *)malloc(sizeof(*room));
	room->room_id = id;
	room->xy[0] = xy[0];
	room->xy[1] = xy[1];
	room->name = ft_strdup(name);
	room->type = type;
	room->path = NULL;
	room->next = NULL;
	return (room);
}

// main for testing struct leaks
int main(void)
{
	t_room			*now;
	t_room			*tmp;
	int				xy[2];
	int				n;
	char			**s;
	unsigned char	e;

	xy[0] = 0;
	xy[1] = 1;
	e = 0;
	s = ft_strsplit("a0b0c0d0e0f", '0');
	now = add(s[xy[0]], xy, 1, 2);
	tmp = now;
	while (xy[0] < 5)
	{
		e = 0;
		xy[0] += 1;
		xy[1] += 3;
		if (xy[0] == 5)
			e = 4;
		tmp->next = add(s[xy[0]], xy, 1, e);
		tmp = tmp->next;
	}
	rpush(&now, now->next);
	rpush(&now, now->next->next);
	rpush(&(now->next), now->next->next->next);
	rpush(&(now->next->next), now->next->next->next->next);
	rpush(&(now->next->next->next), now->next->next->next->next->next);
	rpush(&(now->next->next->next->next), now->next->next->next->next->next);
	rpush(&(now->next), now->next->next->next->next->next);
	pathfinder(&now);
	n = path_size(&now);
	e = 1;
	while (e <= n + 7)
	{
		print_solution(&now, 7, e);
		e++;
	}
	free2dArray(s);
	froom(&now);
	return (0);
}

