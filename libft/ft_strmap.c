/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:53:10 by svan-nie          #+#    #+#             */
/*   Updated: 2019/06/05 13:56:21 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *str, char (*f)(char))
{
	size_t	i;
	size_t	len;
	char	*new_str;

	if (!str)
		return (NULL);
	i = 0;
	len = ft_strlen(str);
	new_str = malloc(len * sizeof(char) + 1);
	if (!new_str)
		return (NULL);
	while (i < len)
	{
		new_str[i] = f(str[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
