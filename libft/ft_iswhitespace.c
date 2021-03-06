/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 10:53:55 by svan-nie          #+#    #+#             */
/*   Updated: 2019/06/05 11:16:48 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iswhitespace(char c)
{
	if ((c == ' ') || (c == '\t') || (c == '\f') ||
			(c == '\r') || (c == '\v') || (c == '\n'))
		return (1);
	return (0);
}
