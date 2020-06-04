/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 07:39:51 by svan-nie          #+#    #+#             */
/*   Updated: 2019/06/11 12:49:59 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*temp;
	size_t		len;
	size_t		count;
	size_t		i;

	i = 0;
	len = 0;
	if (!s)
		return (NULL);
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
	{
		len++;
		if (s[len] == '\0')
			return (ft_strdup(""));
	}
	count = len;
	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	if (!(temp = ft_strnew(len - count + 1)))
		return (NULL);
	while (count < len + 1)
		temp[i++] = s[count++];
	temp[i] = '\0';
	return (temp);
}
