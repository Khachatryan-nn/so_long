/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:16:18 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/26 22:40:40 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	parsing(char const *arg)
{
	char	*s;

	s = ft_strchr(arg, '.');
	printf("%s\n", s);
	return ;
}
