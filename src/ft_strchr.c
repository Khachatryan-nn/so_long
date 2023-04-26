/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:18:37 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/26 22:40:31 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strchr(char *str, char c)
{
	while (*str != c && *str != '\0')
		str++;
	if (*str == c)
		return (str);
	return (NULL);
}
