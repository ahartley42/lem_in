/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 12:43:21 by svan-nie          #+#    #+#             */
/*   Updated: 2019/05/28 08:54:13 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t count;

	count = 0;
	while (src[count] != '\0' && (count < n))
	{
		dest[count] = src[count];
		count++;
	}
	while (count < n)
	{
		dest[count] = 0;
		count++;
	}
	return (dest);
}
