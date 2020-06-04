/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 08:35:53 by svan-nie          #+#    #+#             */
/*   Updated: 2019/05/27 13:49:40 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *string, const char *word)
{
	int count;
	int count2;

	count = 0;
	count2 = 0;
	if (word[count] == '\0')
		return (char *)&string[count];
	while (string[count] != '\0')
	{
		while (string[count + count2] == word[count2] && word[count2])
		{
			count2++;
		}
		if (word[count2] == '\0')
			return (char *)&string[count];
		count2 = 0;
		count++;
	}
	return (NULL);
}
