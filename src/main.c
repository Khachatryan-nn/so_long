/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:06:39 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/03 12:39:23 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argv, char **argc)
{
	char	**s;
	void	*mlx_ptr;
	void	*window;
	t_point	size;
	(void) window;

	if (argv != 2)
	{
		write(2, "Error: there aren't inputs\n", 28);
		return (1);
	}
	s = parsing(argc[1]);
	mlx_ptr = mlx_init();
	map_size(s, &size);
	window = mlx_new_window(mlx_ptr, size.x * 50, size.y * 50, "so_long");
	free(s);
	s = 0;
	return (1);
}
