/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:06:39 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/05 18:34:57 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argv, char **argc)
{
	char	**s;
	t_point	size;
	t_mlx	mlx;
	int		height;
	int		width;

	if (argv != 2)
	{
		write(2, "Error: there aren't inputs\n", 28);
		return (1);
	}
	height = 48;
	width = 48;
	s = parsing(argc[1]);
	map_size(s, &size);
	mlx_start(&mlx, size, s);
	free_matrix(s, size.y);
	return (1);
}
