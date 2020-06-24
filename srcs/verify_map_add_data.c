/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map_add_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 22:26:16 by svan-nie          #+#    #+#             */
/*   Updated: 2020/06/08 22:26:16 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void    check_if_pipe(t_room *lem_head,char **twodarray, int *i, unsigned char *dip_Switch)
{
	int strlenpipe;
	int j;

	strlenpipe = 0;
	j = *i;
	if ((strlenpipe = ft_strlen_space(twodarray[j], twodarray, lem_head)) && twodarray[j][strlenpipe] == '\0' && twodarray[j][0] != '#')
	{
		if ((strlenpipe = ft_strlen_pipes(twodarray[j], twodarray, lem_head)) == 1)
			ft_add_pipe_address(lem_head, twodarray, &j);
		else
			err_duo(&lem_head, twodarray);
		*dip_Switch |= 8;
		*i = j;
	}
}

static void    ft_check_for_random_ants(char **twodarray, int *i, t_room *lem)
{
	int j;

	j = *i;
	if (check_int(twodarray[j]) == 1)
		err_duo(&lem, twodarray);
	*i = j;
}

static void    ft_check_start_end_room(char **twodarray,int *ij, unsigned char *dip_Switch, t_room *lem)
{
	if (twodarray[ij[0]][0] == '#' && twodarray[ij[0]][1] == '#')
	{
		ij[2] = ft_check_start_end(twodarray[ij[0]]);
		ft_keep_track_start_end(ij[2], dip_Switch, twodarray, lem);
		if ((*dip_Switch & 32) == 32)
			ft_check_start_room(twodarray, &ij[0], lem);
		if ((*dip_Switch & 64) == 64)
			ft_check_end_room(twodarray, &ij[0], lem);
	}
}

static void    ft_skip_comment(char **twodarray,int *ij)
{
	if (twodarray[ij[0]][0] == '#' && twodarray[ij[0]][1] != '#')
		ij[0]++;
}

void    verify_map_and_data(t_room *lem_tmp, t_room *lem_head, char **twodarray, int *ant_amount)
{
	int     ij[3];
	int     slen;
	unsigned char   dip_Switch;

	ij[0] = 0;
	ij[1] = 0;
	ij[2] = 0;
	ft_check_one(twodarray, &ij[0], lem_head);
	ft_check_for_ant_amount(twodarray, &ij[0], ant_amount, lem_head);
	while (twodarray[ij[0]])
	{
		slen = 0;
		ft_skip_comment(twodarray, &ij[0]);
		ft_check_for_random_ants(twodarray, &ij[0], lem_head);
		ft_check_start_end_room(twodarray, ij, &dip_Switch, lem_head);
		if ((slen = ft_strlen_space(twodarray[ij[0]], twodarray, lem_head)) \
				&& twodarray[ij[0]][slen] == ' ' && twodarray[ij[0]][slen + 1])
		{
			ft_check_valid_room(lem_tmp, lem_head, twodarray, ij, &dip_Switch);
			lem_tmp = lem_tmp->next;
		}
		check_if_pipe(lem_head, twodarray, &ij[0], &dip_Switch);
		ij[0]++;
	}
	ft_check_for_error(dip_Switch, twodarray, lem_head);
}

/*
** line 22
** ft_strlen_space
** checks to see if pipes is valid
** line 36
** ft_check_for_random_ants
** checks to see if more than one ant
** line 51
** ft_check_start_end_room
** checks for start and end
** line 62
** ft_skip_comment
** checks for comment
** line 90
** check_if_pipe
** checks to see if pipes is valid
** line 94
** ft_check_for_error
** saving lines checks to see if end and start or trackroom or trackpipe is on if not error
*/
