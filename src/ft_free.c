/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:59:41 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/10 22:20:17 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
			mlx_destroy_image(MLX.ptr, x[i]);
		i++;
	}
	free(x);
	x = 0;
}
