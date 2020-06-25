/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map_functions_one.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 16:23:49 by svan-nie          #+#    #+#             */
/*   Updated: 2020/06/21 16:23:49 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int    ft_check_start_end(char *tda)
{
	if (ft_strequ(tda, "##start"))
		return (0);
	else if (ft_strequ(tda, "##end"))
		return (1);
	return (2);
}

void ft_keep_track_start_end(int t, unsigned char *dip, char **tda, t_room *lem)
{
	if (t == 0)
	{
		if ((*dip & 2) == 2)
			err_duo(&lem, tda);
		*dip |= 32;
		if ((*dip & 2) == 0)
			*dip |= 2;
	}
	if (t == 1)
	{
		if ((*dip & 4) == 4)
			err_duo(&lem, tda);
		*dip |= 64;
		if ((*dip & 4) == 0)
			*dip |= 4;
	}
}

char    *ft_find_firstName(char **tda, int *i)
{
	char    *firstName;
	int     len;
	int     j;

	len = 0;
	j = *i;
	len = ft_strlen_hyphen(tda, i);
	firstName = ft_strnew(len);
	ft_strcpy_to_hyphen(firstName, tda[j], '-');
	return (firstName);
}

char    *ft_find_lastName(char **tda, int *i)
{
	char    *lastName;
	int     len;
	int     len2;
	int     j;

	len = 0;
	j = *i;
	len = ft_strlen_hyphen(tda, i);
	len2 = ft_strlen_till_end(tda, i, &len);
	lastName = ft_strnew(len2);
	ft_strcpy_after_hyphen(lastName, tda[j], '-');
	return (lastName);
}

char    *ft_find_firstName_space(char **tda, int *i)
{
	char    *firstName;
	int     len;
	int     j;

	len = 0;
	j = *i;
	len = ft_strlen_space_this(tda, i);
	firstName = ft_strnew(len);
	ft_strcpy_to_hyphen(firstName, tda[j], ' ');
	return (firstName);
}
