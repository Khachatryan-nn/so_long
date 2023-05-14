/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 00:08:19 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/14 20:04:56 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	additional_checks(char **map, char *s)
{
	int	i;
	int	j;
	int	counter_p;
	int	counter_e;

	i = -1;
	counter_p = 0;
	counter_e = 0;
	while (map[++i] != NULL)
	{
		j = -1;
		while (map[i][++j] != '\0')
		{
			if (map[i][j] == 'E')
				counter_e++;
			if (map[i][j] == 'P')
				counter_p++;
		}
	}
	if (counter_e != 1 || counter_p != 1)
	{
		write (2, "ERROR: Invalid map configuration.\n", 34);
		exit (free_strings(map, s));
	}
}

void	map_size(char **map, t_mlx *size)
{
	(*size).x = 0;
	(*size).y = 0;
	while (map[0][(*size).x] != '\0')
		(*size).x++;
	while (map[(*size).y] != 0)
		(*size).y++;
	(*size).map = map;
}
