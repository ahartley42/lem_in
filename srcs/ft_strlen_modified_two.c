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

int ft_strlen_hyphen(char **twodarray,int *i)
{
    int len;
    int j;
    j = *i;
    len = 0;

    while (twodarray[j][len] != '-')
    {
        len++;
    }
    return (len);
}

int    ft_strlen_till_end(char **twodarray, int *i, int *len)
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