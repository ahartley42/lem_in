/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 09:01:06 by svan-nie          #+#    #+#             */
/*   Updated: 2019/05/30 10:01:06 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t count;

	count = 0;
	if (!s1 || !s2)
		return (0);
	while (count < n)
	{
		if (s1[count] != s2[count])
			return (0);
		count++;
	}
	return (1);
}
