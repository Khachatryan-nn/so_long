/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:59:41 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/14 19:51:07 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_win(t_mlx *mlx, int i, int j, char c)
{
	if (c == 'u')
		(*mlx).map[i - 1][j] = 'P';
	if (c == 'd')
		(*mlx).map[i + 1][j] = 'P';
	if (c == 'l')
		(*mlx).map[i][j - 1] = 'P';
	if (c == 'r')
		(*mlx).map[i][j + 1] = 'P';
	(*mlx).map[i][j] = '0';
	printf("\033[38;5;202mYou win!\033[0m\n");
	close_window(mlx);
}

int	free_strings(char **x, char *str)
{
	int	i;

	i = 0;
	while (x[i] != NULL)
	{
		free(x[i]);
		i++;
	}
	free(x);
	x = 0;
	if (str)
	{
		free(str);
		str = 0;
	}
	return (0);
}

int	free_matrix(char **x, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(x[i]);
		i++;
	}
	free(x);
	x = 0;
	return (0);
}

void	free_vmatrix(t_mlx *mlx, void **x, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (x[i])
			mlx_destroy_image((*mlx).ptr, x[i]);
		i++;
	}
	free(x);
	x = 0;
}
