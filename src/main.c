/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:06:39 by tikhacha          #+#    #+#             */
/*   Updated: 2023/06/07 15:59:12 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argv, char **argc)
{
	t_mlx	mlx;

	if (argv != 2)
	{
		write(2, "Error: there aren't inputs\n", 28);
		return (1);
	}
	mlx.map = parsing(argc[1]);
	map_size(mlx.map, &mlx);
	mlx_start(&mlx);
	return (1);
}
