/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:06:39 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/10 22:25:37 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argv, char **argc)
{
	t_mlx	mlx;
	int		height;
	int		width;
	(void) height;
	(void) width;

	if (argv != 2)
	{
		write(2, "Error: there aren't inputs\n", 28);
		return (1);
	}
	height = 48;
	width = 48;
	mlx.map = parsing(argc[1]);
	map_size(mlx.map, &mlx);
	mlx_start(&mlx);
	free(mlx.ptr);
	t_mlx new;
	new.h = 0;
	mlx = new;
	//system("leaks so_long");
	return (1);
}
