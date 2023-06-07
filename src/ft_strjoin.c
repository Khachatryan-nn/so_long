/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:03:43 by tikhacha          #+#    #+#             */
/*   Updated: 2023/06/07 15:59:12 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		n;
	int		k;
	int		i;
	char	*p;

	if (!s1 || !s2)
		return (0);
	i = 0;
	k = ft_strlen(s1);
	n = k + ft_strlen(s2) + 1;
	p = (char *)malloc(sizeof(char) * n);
	if (!p)
		return (NULL);
	p[n - 1] = '\0';
	while (i < n)
	{
		if (i < k)
			p[i] = s1[i];
		else if (*s2)
			p[i] = *s2++;
		i++;
	}
	free(s1);
	s1 = 0;
	return (p);
}
