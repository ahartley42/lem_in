/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_modified.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 22:03:48 by svan-nie          #+#    #+#             */
/*   Updated: 2020/06/08 22:03:48 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int ft_strlen_space(char *str, char **twodarray, t_room *lem)
{
	size_t i;

	i = 0;
	if(str[i] == 'L')
		err_duo(&lem, twodarray);
	while(str[i] != '\0')
	{
		if (str[i] == ' ')
			break;
		i++;
	}
	return (i);
}

int ft_strlen_space_error(char *str, char **twodarray, t_room *lem)
{
	int i;

	i = 0;
	if(str[i] == 'L')
		err_duo(&lem, twodarray);
	while(str[i] != '\0')
	{
		if (str[i] == '-')
			err_duo(&lem, twodarray);
		if (str[i] == ' ')
			break;
		i++;
	}
	return (i);
}

void ft_strlen_space_count(char *str, char **twodarray, t_room *lem)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' '){
			k++;
			if (str[i + 1] == ' ')
				err_duo(&lem, twodarray);
		}
		i++; 
	}
	if (k != 2)
		err_duo(&lem, twodarray);
}

int    ft_strlen_pipes(char *str, char **twodarray, t_room *lem)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if(str[i] == 'L')
		err_duo(&lem, twodarray);
	if (str[i] == '-')
		err_duo(&lem, twodarray);
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			j++;
		i++;
	}
	if (j != 1)
		err_duo(&lem, twodarray);
	return (1);
}

void    ft_strlen_2d_array(char **str, t_room *lem)
{
	int i;
	int k;
	int trackHyphen;
	int	count;

	i = -1;
	trackHyphen = 0;
	while (str[++i])
	{
		k = -1;
		count = 0;
		while (str[i][++k])
		{
			if (str[i][0] == 'L')
				err_duo(&lem, str);
			if (str[i][k] == '-')
			{
				k = -1;
				while (str[i][++k])
				{
					if (str[i][k] == ' ')
						count++;
				}
				if (count > 1)
					break ;
				trackHyphen++;
				break;
			}
		}
		if (trackHyphen == 1)
			break;
	}
	while (str[i])
	{
		k = 0;
		trackHyphen = 0;
		while (str[i][k])
		{
			if (str[i][k] == '-')
				trackHyphen++;
			if (str[i][0] == '#' && (str[i][1] != '#' || str[i][1] == '\0'))
				trackHyphen++;
			k++;
		}
		if (trackHyphen == 0)
			err_duo(&lem, str);
		i++;
	}
	ft_strlen_check_names(str, lem);
} //50

/*
** #looking for space in ft_strlen if it comes accross L error out
** #looking for space in ft_strlen if it comes accross L or - in a name it 
** will error out
** #counts the amount of spaces if smaller than 2 or bigger than two error
** #checking to see if there is only 1 '-' in the name else error
** #checks to see if the pipes are in the correct order it will only skip
** through comments if anthing else in under the pipes it will display error
*/
