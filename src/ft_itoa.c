/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:36:20 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/11 11:36:37 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int      ft_lenght(int n)
{
        int     k;

        k = 0;
        if (n <= 0)
                k++;
        while (n != 0)
        {
                n /= 10;
                k++;
        }
        return (k);
}

static char     ft_chr(int n, int lenght)
{
        while (--lenght)
                n /= 10;
        n %= 10;
        if (n < 0)
                n *= -1;
        return (n + '0');
}

char    *ft_itoa(int n)
{
        char    *p;
        int             i;
        int             lenght;

        i = 0;
        lenght = ft_lenght(n);
        p = (char *)malloc(sizeof(char) * (lenght + 1));
        if (!p)
                return (0);
        if (n < 0)
        {
                p[i++] = '-';
                lenght--;
        }
        while (lenght)
                p[i++] = ft_chr(n, lenght--);
        p[i] = '\0';
        return (p);
}
