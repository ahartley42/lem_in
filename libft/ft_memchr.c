/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:14:55 by svan-nie          #+#    #+#             */
/*   Updated: 2019/05/28 08:50:42 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*start;
	unsigned char	usc;
	size_t			count;

	start = (unsigned char*)str;
	usc = (unsigned char)c;
	count = 0;
	while (count < n)
	{
		if (start[count] == usc)
			return ((void*)&start[count]);
		count++;
	}
	return (NULL);
}
