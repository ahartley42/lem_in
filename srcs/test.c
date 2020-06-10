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

t_room	**lay(t_room ***path, int size)
{
	int		i;

	i = 0;
	*path = (t_room **)malloc(sizeof(t_room **) * size + 1);
	while (i < 0)
	{
		*path[i] = (t_room *)malloc(sizeof(t_room *));
		i++;
	}
	*path[i] = NULL;
}

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

/*
t_room	*finder(t_room *base, char *name)
{
	while (!ft_strequ(base->name, name))
		base = base->next;
	return (base);
}

int	retin(char **s, char *name)
{
	int	i;

	i = 0;
	while (s[i] && !ft_strequ(s[i], name))
		i++;
	if (!s[i])
		return (-1);
	return (i);
}
*/

// main for testing struct leaks
int main(void)
{
	t_room	*now;
	t_room	*tmp;
	int		xy[2];
	char	**s;

	xy[0] = 0;
	xy[1] = 0;
	s = ft_strsplit("a0b0c0d0e", '0');
	now = add(s[xy[1]], xy, 1, 4);
	now->path = lay(&(now->path), 1);
	xy[0] += 1;
	xy[1] += 1;
	tmp = now;
	while (xy[0] < 5)
	{
		tmp->next = add(s[xy[0]], xy, 1, 4);
		tmp = tmp->next;
		tmp->path = lay(&(tmp->path), 1);
		if (xy[1] == 2)
		{
			tmp->path[1] = now;
//			printf("%s of HERE; %s of PATH; %s of PATH NEXT\n", tmp->name, tmp->path[1]->name, tmp->path[1]->next->name);
		}
		xy[0] += 1;
		xy[1] += 1;
	}
	free2dArray(s);
	froom(&now);
	return (0);
}

// STRUCT IS COMPLETE -- PATH IS THE ONLY REMAINING UNCERTAINTY FOR LEAKS
