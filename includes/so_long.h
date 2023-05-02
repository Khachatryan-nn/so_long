/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:07:10 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/02 18:25:00 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
int		free_strings(char **x, char *str);
int		ft_strcmp(char *str1, char *str2);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char *str, char c);
char	*ft_strrchr(char *str, char c);
void	flood_fill(char **tab);
char	*get_next_line(int fd);
char	*ft_strdup(char *str);
int		ft_strlen(char *str);
char	**parsing(char *arg);

#endif