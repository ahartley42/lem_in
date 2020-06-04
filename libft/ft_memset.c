/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:23:47 by svan-nie          #+#    #+#             */
/*   Updated: 2019/05/21 11:48:34 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int x, size_t len)
{
	unsigned char	*ptr;
	size_t			count;

	ptr = str;
	count = 0;
	while (count < len)
	{
		ptr[count] = x;
		count++;
	}
	return (str);
}
