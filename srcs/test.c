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

void	froom(t_room **lst)
{
	char 	*s;
	t_room	**p;

	if ((*lst)->next)
	{
//		printf("%d\n", (*lst)->next->xy[0]);
		froom(&((*lst)->next));
	}
	s = (*lst)->name;
	p = (*lst)->path;
//	printf("%s\n", s);
	free(s);
	free(p);
	free(*lst);
}

// main for testing struct leaks
int main(void)
{
	t_room	*now;
	t_room	*tmp;
	int		xy[2];
	char	**s;

	xy[0] = 0;
	xy[1] = 1;
	s = ft_strsplit("a0b0c0d0e", '0');
	now = add(s[xy[0]], xy, 1, 4);
	tmp = now;
	while (xy[0] < 4)
	{
		xy[0] += 1;
		xy[1] += 3;
		tmp->next = add(s[xy[0]], xy, 1, 4);
		tmp = tmp->next;
	}
	rpush(&now, now->next);
	rpush(&now, now->next->next);
	rpush(&now, now->next->next->next);
	printf("-----\nROOM1\n-----\n\nname: %s\n\n", now->name);
	printf("-----\nROOM2\n-----\n\nname: %s\n\n", now->path[0]->name);
	printf("-----\nROOM3\n-----\n\nname: %s\n\n", now->path[1]->name);
	printf("-----\nROOM4\n-----\n\nname: %s\n\n", now->path[2]->name);
	printf("\e[5;33mDELETING PATH 1\e[0m\n\n");
	rpop(&now, 0);
	printf("-----\nROOM1\n-----\n\nname: %s\n\n", now->name);
	printf("-----\nROOM3\n-----\n\nname: %s\n\n", now->path[0]->name);
	printf("-----\nROOM4\n-----\n\nname: %s\n\n", now->path[1]->name);
	free2dArray(s);
	froom(&now);
	return (0);
}

// STRUCT IS COMPLETE -- PATH IS THE ONLY REMAINING UNCERTAINTY FOR LEAKS
