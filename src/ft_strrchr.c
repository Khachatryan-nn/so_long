/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:18:37 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/29 00:15:36 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
** The ft_strrchr() function locates the last occurrence of c (converted to a
** char) in the string pointed to by s.  The terminating null character is
** considered to be part of the string; therefore if c is '\0', the functions
** locate the terminating '\0'. Returns a pointer to the located character,
** or NULL if the character does not appear in the string.
*/
char	*ft_strrchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (i >= 0 && str[i] != c)
		i--;
	if (str[i] == c)
		return (str + i);
	return (NULL);
}
