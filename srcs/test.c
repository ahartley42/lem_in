#include "../includes/lem_in.h"
#include "../libft/libft.h"
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
	
	room = (t_room *)malloc(sizeof(room));
	room->room_id = id;
	room->xy[0] = xy[0];
	room->xy[1] = xy[1];
	room->name = ft_strdup(name);
	room->type = type;
	room->path = NULL;
	room->next = NULL;
	printf("passed thru\n");
	return (room);
}

void	froom(t_room **lst)
{
	if ((*lst)->next)
		froom(&((*lst)->next));
	printf("NO?\n");
//	free((*lst)->name);
	printf("YES\n");
	free(*lst);
	printf("freed\n");
}

int main(void)
{
	t_room	*now;
	int		xy[2];

	xy[0] = 15;
	xy[1] = 25;
	now = add("FIRST", xy, 1, 4);
	froom(&now);
	sleep(60);
	return (0);
}
