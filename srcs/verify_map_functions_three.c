/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map_functions_three.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 20:37:48 by svan-nie          #+#    #+#             */
/*   Updated: 2020/06/23 20:37:48 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void    ft_check_one(char **tda, int *i, t_room *lem)
{
	int j;

	j = *i;
	while (tda[j])
		j++;
	if (j < 2)
		err_duo(&lem, tda);
}

void    ft_check_for_ant_amount(char **tda, int *i, int *ants, t_room *lem)
{
	int j;

	j = *i;
	while (tda[j])
	{
		if (tda[j][0] == '#')
		{
			if (tda[j][0] == '#' && tda[j][1] == '#')
				err_duo(&lem, tda);
			j++;
		}
		if (tda[j][0] == '#' && tda[j][1] == '#')
			err_duo(&lem, tda);
		if (check_int(tda[j]) == 1)
		{
			*ants = ft_atoi(tda[j]);
			break;
		}
		j++;
	}
	if (*ants <= 0)
		err_duo(&lem, tda);
	j++;
	*i = j;
}

void ft_check_start_room(char **tda, int *i, t_room *lem)
{
	int j;
	int slen;

	j = *i;
	slen = 0;
	if (tda[j + 1])
		j++;
	else
		err_duo(&lem, tda);
	while ((tda[j][0] == '#' && (tda[j][1] != '#' || tda[j][1] == '\0')) || \
			(tda[j][0] == '#' && tda[j][1] == '#'))
		j++;
	if ((slen = ft_strlen_space(tda[j], tda, lem)) && tda[j][slen] == ' ' && \
			tda[j][slen + 1])
		;
	else
		err_duo(&lem, tda);
	*i = j;
}

void ft_check_end_room(char **tda, int *i, t_room *lem)
{
	int j;
	int slen;

	j = *i;
	slen = 0;
	if (tda[j + 1])
		j++;
	else
		err_duo(&lem, tda);
	while ((tda[j][0] == '#' && (tda[j][1] != '#' || tda[j][1] == '\0')) || \
			(tda[j][0] == '#' && tda[j][1] == '#'))
		j++;
	if ((slen = ft_strlen_space(tda[j], tda, lem)) && tda[j][slen] == ' ' && \
			tda[j][slen + 1])
		;
	else
		err_duo(&lem, tda);
	*i = j;
}

void    ft_check_valid_room(t_room *tmp, t_room *lem, char **tda, int *ij, \
		unsigned char *dip)
{
	char    **check_rooms;

	ft_strlen_space_count(tda[ij[0]], tda, lem);
	check_rooms = ft_strsplit(tda[ij[0]], ' ');
	ft_strlen_space_error(check_rooms[0], tda, lem);
	if (check_int(check_rooms[1]) == 1 && check_int(check_rooms[2]) == 1)
	{
		if (*dip & 96)
		{
			if (*dip & 32)
				ft_add_start_room(tmp, check_rooms, &ij[1]);
			else
				ft_add_end_room(tmp, check_rooms, &ij[1]);
			*dip &= 159;
		}
		else
			ft_add_rooms(tmp, check_rooms, &ij[1]);
	}
	else
	{
		free2dArray(check_rooms);
		err_duo(&lem, tda);
	}
	*dip |= 16;
	free2dArray(check_rooms);
}

/*
** #ft_check_for_ant_amount
** #looking for ant_amount once found breaks out and returns ant amount
** 	if not found returns error
** #j++ incrementing past the ant_amount
**
** #ft_strlen_space_count
** #counting the amount of spaces more or less than 2 displays error
** 
** #ft_strlen_space_error
** #checks for name starting with L and - inside the name
*/
