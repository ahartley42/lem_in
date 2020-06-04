#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_room
{
	int				room_id; //	id of room
	int				ant_id; //	id of ant
	int				tvd; //		counter for how many times transversed
	char			*name; //	name of room
	unsigned char	type; //	4 = end, 2 = start, 1 = occupied
	struct s_room	**next; //	array of linked paths
}					t_room;

#endif
