/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_modified_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 18:22:33 by svan-nie          #+#    #+#             */
/*   Updated: 2020/06/15 18:22:33 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_strlen_hyphen(char **twodarray, int *i)
{
	int len;
	int j;
	j = *i;
	len = 0;

	while (twodarray[j][len] != '-')
		len++;
	return (len);
}

int		ft_strlen_space_this(char **twodarray, int *i)
{
	int len;
	int j;
	j = *i;
	len = 0;

	while (twodarray[j][len] != '\0' && twodarray[j][len] != ' ')
		len++;
	return (len);
}

int		ft_strlen_till_end(char **twodarray, int *i, int *len)
{
	int j;
	int length;
	int len2;

	j = *i;
	length = *len;
	len2 = 0;
	length++;
	while (twodarray[j][length] != '\0')
	{
		len2++;
		length++;
	}
	return (len2);
}

void	ft_strlen_check_names(char **str, t_room *lem)
{
	int i;
	int k;
	int strlen;
	char *firstName;
	char *compareName;

	i = 0;
	k = 0;
	while (str[i] && str[i + 1])
	{
		strlen = 0;
		if (str[i][0] == '#')
			i++;
		if ((strlen = ft_strlen_space(str[i], str, lem)) && str[i][strlen] == ' ' && str[i][strlen + 1])
		{
			k = i;
			if (str[i + 1] == NULL)
				break ;
			k++;
			firstName = ft_find_firstName_space(str, &i);
			while (str[k])
			{
				compareName = ft_find_firstName_space(str, &k);
				if (ft_strequ(firstName, compareName))
				{
					free_two_strings(firstName, compareName);
					err_duo(&lem, str);
				}
				free(compareName);
				k++;
			}
			free(firstName);
		}
		i++;
	}
}
