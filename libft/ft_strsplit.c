/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahartley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 09:52:47 by ahartley          #+#    #+#             */
/*   Updated: 2019/06/12 15:46:00 by ahartley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(const char *s, char c)
{
	int	i;
	int	ans;

	i = 0;
	ans = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			ans++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (ans);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ans;
	int		i;
	int		j;
	int		k;

	if (!s || !(ans = (char **)malloc(sizeof(char *) * ft_wordcount(s, c) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (j < ft_wordcount(s, c))
	{
		k = 0;
		while (s[i] == c)
			i++;
		while (s[i + k] && s[i + k] != c)
			k++;
		if (!(ans[j] = ft_strsub(s, i, k)))
			return (NULL);
		i = i + k;
		j++;
	}
	ans[j] = 0;
	return (ans);
}
/*
** i = s index
** j = 1st index of ans
** k = word length after split
** i = i + k is necessary for i to jump to the next split or null
** strncpy used to copy the entire string of 'k' length to ans[j]
** j increments to iterate through the entire 2D array
*/
