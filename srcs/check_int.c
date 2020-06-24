/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 12:06:43 by svan-nie          #+#    #+#             */
/*   Updated: 2020/06/22 12:06:45 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	check_int(char *s)
{
	char *tmp;

	if (!(tmp = ft_itoa(ft_atoi(s))))
		return (-1);
	if (!ft_strequ(tmp, s))
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}
