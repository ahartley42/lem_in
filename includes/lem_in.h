/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 12:07:29 by svan-nie          #+#    #+#             */
/*   Updated: 2020/06/24 19:31:23 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_room
{
	int				room_id;
	int				ant_id;
	int				run;
	int				xy[2];
	char			*name;
	unsigned char	type;
	struct s_room	**path;
	struct s_room	*next;
}					t_room;
t_room 				*initialize_struct();

void    			ft_add_rooms(t_room *lem, char **room_data, int *j);
void    			ft_add_start_room(t_room *lem, char **room_data, int *j);
void    			ft_add_end_room(t_room *lem, char **room_data, int *j);
int					check_int(char *s);
void    			free2dArray(char **str);
void				froom(t_room **lst);
void				free_two_strings(char *s1, char *s2);
char				**read_map();
void 				verify_map_and_data(t_room *lem_tmp, t_room *lem_head, char **twodarray, int *ant_amount);
int    				ft_check_start_end(char *twodarray);
void 				ft_keep_track_start_end(int total, unsigned char *dip_Switch, char **twodarray, t_room *lem);
char    			*ft_find_firstName(char **twodarray, int *i);
char    			*ft_find_lastName(char **twodarray, int *i);
char    			*ft_find_firstName_space(char **twodarray, int *i);
int 				ft_check_address_exists(char *firstName, char *lastName, t_room *lem_head);
void    			check_x_and_y(t_room *lem_head, char **twodarray, char *firstName, char *lastName);
void    			ft_add_pipe_address(t_room *lem_head,char **twodarray, int *i);
void    			ft_check_one(char **twodarray, int *i, t_room *lem);
void				ft_check_for_ant_amount(char **twodarray, int *i, int *ant_amount, t_room *lem);
void 				ft_check_start_room(char **twodarray, int *i, t_room *lem);
void 				ft_check_end_room(char **twodarray, int *i, t_room *lem);
void    			ft_check_valid_room(t_room *lem_tmp, t_room *lem, char **twodarray, int *ij, unsigned char *dip_Switch);
int					ft_strlen_pipes(char *str, char **twodarray, t_room *lem);
void 				ft_strlen_space_count(char *str, char **twodarray, t_room *lem);
int 				ft_strlen_space_error(char *str, char **twodarray, t_room *lem);
int 				ft_strlen_space(char *str, char **twodarray, t_room *lem);
void    			ft_strlen_2d_array(char **str, t_room *lem);
int 				ft_strlen_hyphen(char **twodarray,int *i);
int 				ft_strlen_space_this(char **twodarray,int *i);
int    				ft_strlen_till_end(char **twodarray, int *i, int *len);
void    			ft_strlen_check_names(char **str, t_room *lem);
char				*ft_strcpy_to_hyphen(char *dest, const char *src, char n);
char				*ft_strcpy_after_hyphen(char *dest, const char *src, char n);
void				rpush(t_room **room, t_room *add);
void				rpop(t_room **room, int i);
void 				ft_check_for_error(unsigned char dip_Switch, char **twodarray, t_room *lem_head);
void 				ft_wrong_name_error(char *firstName, char *lastName, t_room *lem_head, char **twodarray);
int					pathfinder(t_room **room);
int					path_size(t_room **room);
void				print_solution(t_room **room, int ants, int i);
void				err_map(char **map);
void				err_room(t_room **room);
void				err_duo(t_room **room, char **map);

#endif

/*
** ::struct::
**
** id of room
** id of ant
** counter for how many times transversed
** x and y coordinates
** name of room
** 4 = end, 2 = start, 1 = occupied
** array of linked paths
** node to next
*/
