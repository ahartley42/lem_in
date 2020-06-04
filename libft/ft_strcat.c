/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 12:54:33 by svan-nie          #+#    #+#             */
/*   Updated: 2019/05/20 13:29:25 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *str1, const char *str2)
{
	int len;
	int len2;

	len = 0;
	while (str1[len] != '\0')
		len++;
	len2 = 0;
	while (str2[len2] != '\0')
	{
		str1[len + len2] = str2[len2];
		len2++;
	}
	str1[len + len2] = '\0';
	return (str1);
}
