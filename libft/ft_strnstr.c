/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:25:48 by svan-nie          #+#    #+#             */
/*   Updated: 2019/06/11 07:48:24 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *word, size_t len)
{
	size_t len2;

	if (*word == '\0')
		return ((char *)s);
	len2 = ft_strlen(word);
	while (*s != '\0' && len-- >= len2)
	{
		if (*s == *word && ft_memcmp(s, word, len2) == 0)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
