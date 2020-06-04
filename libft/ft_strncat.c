/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:30:14 by svan-nie          #+#    #+#             */
/*   Updated: 2019/05/20 13:37:53 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *str1, const char *str2, size_t n)
{
	size_t len;
	size_t len2;

	len = 0;
	while (str1[len] != '\0')
		len++;
	len2 = 0;
	while (n && str2[len2] != '\0')
	{
		str1[len + len2] = str2[len2];
		len2++;
		n--;
	}
	str1[len + len2] = '\0';
	return (str1);
}
