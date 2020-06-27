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

static void    check_if_pipe(t_room *lem, char **tda, int *i, unsigned char *dp)
{
	int slenpipe;
	int j;

	slenpipe = 0;
	j = *i;
	if ((slenpipe = ft_strlen_space(tda[j], tda, lem)) \
			&& tda[j][slenpipe] == '\0' && tda[j][0] != '#')
	{
		if ((slenpipe = ft_strlen_pipes(tda[j], tda, lem)) == 1)
			ft_add_pipe_address(lem, tda, &j);
		else
			err_duo(&lem, tda);
		*dp |= 8;
		*i = j;
	}
}

static void    ft_check_for_random_ants(char **twodarray, int *i, t_room *lem)
{
	if (check_int(twodarray[(*i)]) == 1)
		err_duo(&lem, twodarray);
}

static void    ft_check_start_end_room(char **tda,int *ij, unsigned char *dip, \
		t_room *lem)
{
	if (tda[ij[0]][0] == '#' && tda[ij[0]][1] == '#')
	{
		ij[2] = ft_check_start_end(tda[ij[0]]);
		ft_keep_track_start_end(ij[2], dip, tda, lem);
		if ((*dip & 32) == 32)
			ft_check_start_room(tda, &ij[0], lem);
		if ((*dip & 64) == 64)
			ft_check_end_room(tda, &ij[0], lem);
	}
}

void    verify_map_and_data(t_room *tmp, t_room *lem, char **tda, int *ants)
{
	int     ij[3];
	int     slen;
	unsigned char   dip;

	ij[0] = 0;
	ij[1] = 0;
	ij[2] = 0;
	ft_check_one(tda, &ij[0], lem);
	ft_check_for_ant_amount(tda, &ij[0], ants, lem);
	while (tda[ij[0]])
	{
		slen = 0;
		ft_check_for_random_ants(tda, &ij[0], lem);
		ft_check_start_end_room(tda, ij, &dip, lem);
		if ((slen = ft_strlen_space(tda[ij[0]], tda, lem)) && \
				tda[ij[0]][slen] == ' ' && tda[ij[0]][slen + 1])
		{
			ft_check_valid_room(tmp, lem, tda, ij, &dip);
			tmp = tmp->next;
		}
		check_if_pipe(lem, tda, &ij[0], &dip);
		ij[0]++;
	}
	ft_check_for_error(dip, tda, lem);
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
** ij[0] = 2d incr
** ij[1] = room id
** ij[2] = total
*/
