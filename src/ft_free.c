/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:59:41 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/02 23:58:18 by tikhacha         ###   ########.fr       */
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

int	free_matrix(char **x)
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
	return (0);
}
