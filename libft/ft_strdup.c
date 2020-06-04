/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 12:19:18 by svan-nie          #+#    #+#             */
/*   Updated: 2019/05/20 12:36:57 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*temp;
	int		len;

	len = 0;
	while (str[len] != '\0')
		len++;
	if (!(temp = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	temp[len] = '\0';
	while (len >= 0)
	{
		temp[len] = str[len];
		len--;
	}
	return (temp);
}
