/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 00:17:30 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/02 14:24:11 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strtrim(char *str, char c)
{
	char	*new;
	int		i;
	int		j;
	int		n;

	i = 0;
	n = 0;
	while ((str[i] == c || str[i] == '\n') && str[i])
		i++;
	j = ft_strlen(str) - 1;
	while ((str[j] == c || str[j] == '\n') && str[j])
		j--;
	new = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!new)
	{
		free(str);
		exit(0);
	}
	while (i <= j)
		new[n++] = str[i++];
	free(str);
	return (new);
}
