#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_base
{
	char 			*name;
	int				id;
	int				ants;
	struct s_base	**next;
}					t_base;

typedef struct		s_room
{
	int				room_id; //	id of room
	int				ant_id; //	id of ant
	int				run; //		counter for how many times transversed
	int				xy[2]; //	x and y coordinates
	char			*name; //	name of room
	unsigned char	type; //	4 = end, 2 = start, 1 = occupied
	struct s_room	**path; //	array of linked paths
	struct s_room	*next; //	node to next
}					t_room;

int				check_int(char *s);
int    			ft_check_ants(char *base);
void    		free2dArray(char **str);

//strlen_modified
int    			ft_strlen_pipes(char *str);
void 			ft_strlen_space_count(char *str);
int 			ft_strlen_space_error(char *str);
int 			ft_strlen_space(char *str);
#endif
