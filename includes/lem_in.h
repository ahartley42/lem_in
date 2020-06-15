#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

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

// initialize_struct setting it to NULL and 0
					t_room *initialize_struct();


//adding Rooms
void    			ft_add_rooms(t_room *lem, char **room_data, int *j);
void    			ft_add_start_room(t_room *lem, char **room_data, int *j);
void    			ft_add_end_room(t_room *lem, char **room_data, int *j);

//checking to see if integer
int					check_int(char *s);
int    				ft_check_ants(char *base);

//Freeing 2dArray and the whole linkList
void    			free2dArray(char **str);
void				froom(t_room **lst);

//Read_map
char				**read_map();

//verify_map
void				verify_map_and_data(t_room *lem, char **twodarray, int *ant_amount);

//strlen_modified
int    				ft_strlen_pipes(char *str);
void 				ft_strlen_space_count(char *str);
int 				ft_strlen_space_error(char *str);
int 				ft_strlen_space(char *str);
void    			ft_strlen_2d_array(char **str);

//algorithm
void				rpush(t_room **room, t_room *add);
void				rpop(t_room **room, int i);

#endif
