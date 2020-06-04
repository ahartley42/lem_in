/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:22:03 by svan-nie          #+#    #+#             */
/*   Updated: 2019/06/11 13:00:55 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*us1;
	unsigned char	*us2;
	int				count;

	us1 = (unsigned char*)s1;
	us2 = (unsigned char*)s2;
	count = 0;
	while (us1[count] != '\0' && us2[count] != '\0')
	{
		if (us1[count] != us2[count])
		{
			if (us1[count] > us2[count])
				return (1);
			return (-1);
		}
		count++;
	}
	if (s1[count])
		return (1);
	if (s2[count])
		return (-1);
	return (0);
}
