/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 00:17:30 by tikhacha          #+#    #+#             */
/*   Updated: 2023/07/13 16:12:06 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strtrim(char *str, char c)
{
	char	*new;
	int		i;
	int		j;
	int		n;

	i = 0;
	n = 0;
	while (str[i] && (str[i] == c || str[i] == '\n'))
		i++;
	j = ft_strlen(str) - 1;
	while (str[j] && (str[j] == c || str[j] == '\n'))
		j--;
	new = (char *)malloc(sizeof(char) * (j - i + 2));
	if (!new)
	{
		write (1, "Error: File is empty.\n", 22);
		free(str);
		exit(0);
	}
	while (i <= j)
		new[n++] = str[i++];
	new[n] = '\0';
	free(str);
	return (new);
}
