/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:17:48 by tikhacha          #+#    #+#             */
/*   Updated: 2023/07/13 16:25:37 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error(int k)
{
	if (k == 0)
	{
		write (2, "ERROR: Invalid file type.\n", 26);
		return (1);
	}
	if (k == 1)
	{
		write (2, "ERROR: Invalid file. Please check and try again.\n", 49);
		return (1);
	}
	if (k == 2)
	{
		write (2, "ERROR: File is empty.\n", 22);
		return (1);
	}
	return (0);
}
