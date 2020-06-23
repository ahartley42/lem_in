/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 12:06:21 by svan-nie          #+#    #+#             */
/*   Updated: 2020/06/22 12:06:22 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	rpop(t_room **room, int i)
{
	while ((*room)->path[i + 1])
	{
		(*room)->path[i] = (*room)->path[i + 1];
		i++;
	}
	(*room)->path[i] = NULL;
}

void	rpush(t_room **room, t_room *add)
{
	int	i;
	int j;
	t_room **new;

	i = 0;
	j = 0;
	if ((*room)->path)
	{
		while ((*room)->path[i])
			i++;
	}
	new = (t_room **)malloc(sizeof(t_room **) * (i + 2));
	while (j < i)
	{
		new[j] = (*room)->path[j];
		j++;
	}
	new[j] = add;
	new[j + 1] = NULL;
	free((*room)->path);
	(*room)->path = new;
}

int	pathfinder(t_room **room)
{
	int	i;

	i = 0;
	(*room)->type |= 1;
	if ((*room)->type & 4)
		return (1);
	else if (!((*room)->path) || !((*room)->path[0]))
		return (0);
	else
	{
		while ((*room)->path[0])
		{
			if (((*room)->path[0]->type & 1) || ((*room)->path[0]->type & 2))
				rpop(room, 0);
			else
			{
				i = pathfinder(&((*room)->path[0]));
				if (i != 1)
					rpop(room, 0);
				else
					return (1);
			}
		}
	}
	(*room)->type ^= 1;
	return (0);
}

int		path_size(t_room **room)
{
	int	i;

	i = 1;
	if ((*room)->type & 4)
		return (1);
	if (!((*room)->path) || !((*room)->path[0]))
		return (0);
	i += path_size(&((*room)->path[0]));
	return (i);
}

void	print_solution(t_room **room, int ants, int i)
{
	if (i <= ants && !((*room)->type & 2))
	{
		ft_putchar('L');
		ft_putnbr(i);
		ft_putchar('-');
		ft_putstr((*room)->name);
	}
	i--;
	if ((*room)->type & 4 || i <= 0)
		ft_putchar('\n');
	else
	{
		if (i < ants && !((*room)->type & 2))
			ft_putchar(' ');
		print_solution(&((*room)->path[0]), ants, i);
	}
}


//
