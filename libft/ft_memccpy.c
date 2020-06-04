/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:50:49 by svan-nie          #+#    #+#             */
/*   Updated: 2019/05/28 08:53:47 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	size_t count;

	count = 0;
	while (count < len)
	{
		((unsigned char*)dest)[count] = ((unsigned char*)src)[count];
		if (((unsigned char*)src)[count] == (unsigned char)c)
			return (&((unsigned char*)dest)[count + 1]);
		count++;
	}
	return (NULL);
}
