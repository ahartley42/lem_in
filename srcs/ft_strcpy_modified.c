/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_modified.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 18:25:18 by svan-nie          #+#    #+#             */
/*   Updated: 2020/06/15 18:25:18 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy_to_hyphen(char *dest, const char *src, char n)
{
	int count;

	count = 0;
	while (src[count] != '\0' && src[count] != n)
	{
		dest[count] = src[count];
		count++;
	}
    dest[count] = '\0';
	return (dest);
}

char	*ft_strcpy_after_hyphen(char *dest, const char *src, char n)
{
	int count;
    int count2;

	count = 0;
    count2 = 0;
    while (src[count] != n)
    count++;
    count++;
	while (src[count] != '\0')
	{
		dest[count2] = src[count];
		count++;
        count2++;
	}
    dest[count2] = '\0';
	return (dest);
}