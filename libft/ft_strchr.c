/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 07:25:43 by svan-nie          #+#    #+#             */
/*   Updated: 2019/05/23 07:56:34 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int count;

	count = 0;
	while (s[count] != c && s[count] != '\0')
	{
		count++;
	}
	if (s[count] == c)
		return ((char*)&s[count]);
	return (NULL);
}
