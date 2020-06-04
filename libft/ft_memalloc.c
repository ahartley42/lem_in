/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:56:43 by svan-nie          #+#    #+#             */
/*   Updated: 2019/06/04 07:39:58 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr;
	size_t			count;

	ptr = (unsigned char*)size;
	count = 0;
	if (!(ptr = (void*)malloc(sizeof(ptr) * size)))
		return (NULL);
	while (count < size)
	{
		ptr[count] = 0;
		count++;
	}
	return (ptr);
}
