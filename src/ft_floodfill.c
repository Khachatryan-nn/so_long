/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:32:04 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/03 00:45:00 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void static	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x)
		return ;
	if (tab[cur.y][cur.x] != to_fill && tab[cur.y][cur.x] != 'C' && \
		tab[cur.y][cur.x] != 'E' && tab[cur.y][cur.x] != '0')
		return ;
	tab[cur.y][cur.x] = '~';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

char static	**make_area(char **zone, t_point size)
{
	char	**new;
	int		i;
	int		j;

	i = -1;
	new = malloc(sizeof(char *) * size.y);
	while (++i < size.y)
	{
		j = -1;
		new[i] = malloc(size.x + 1);
		while (++j < size.x)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}
	return (new);
}

void static	ft_player_coord(char **map, t_point *begin)
{
	(*begin).x = 0;
	while (map[(*begin).x])
	{
		(*begin).y = 0;
		while (map[(*begin).x][(*begin).y])
		{
			if (map[(*begin).x][(*begin).y] == 'P')
				return ;
			(*begin).y++;
		}
		(*begin).x++;
	}
	exit (0);
}

void	exit_check(char **tab, char **area, char *str, t_point size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size.y)
	{
		j = -1;
		while (++j < size.x)
		{
			if (area[i][j] == 'C' || area[i][j] == 'P' || area[i][j] == 'E')
			{
				write (2, "ERROR: You can't collect all coins and escape.\n", 47);
				free_strings(tab, str);
				exit (free_matrix(area));
			}
		}
	}
}

void	flood_fill(char **tab, char *str)
{
	t_point	size;
	t_point	begin;
	char	**area;

	map_size(tab, &size);
	area = make_area(tab, size);
	ft_player_coord(area, &begin);
	fill(area, size, begin, tab[begin.y][begin.x]);
	exit_check(tab, area, str, size);
	free_matrix(area);
}
