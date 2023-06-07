/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:02:27 by tikhacha          #+#    #+#             */
/*   Updated: 2023/06/07 15:59:12 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((char) c == *s)
			return ((char *)s);
		s++;
	}
	if ((char) c == *s)
		return ((char *)s);
	return (NULL);
}
