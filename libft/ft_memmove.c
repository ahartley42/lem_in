/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:24:27 by svan-nie          #+#    #+#             */
/*   Updated: 2019/06/05 10:12:12 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*udest;
	unsigned char	*usrc;
	size_t			count;

	udest = (unsigned char*)dest;
	usrc = (unsigned char*)src;
	count = 0;
	if (usrc < udest)
	{
		while (n-- > 0)
		{
			udest[n] = usrc[n];
		}
	}
	else
	{
		while (count < n)
		{
			udest[count] = usrc[count];
			count++;
		}
	}
	return (udest);
}
