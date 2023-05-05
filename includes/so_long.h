/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:07:10 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/05 18:38:03 by tikhacha         ###   ########.fr       */
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
# include <mlx.h>

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}			t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	img;
}			t_mlx;


char	*ft_substr(char *s, unsigned int start, size_t len);
void	mlx_start(t_mlx *mlx, t_point size, char **map);
void	additional_checks(char **map, char *s);
void	map_size(char **map, t_point *size);
char	**ft_split(char const *s, char c);
int		free_strings(char **x, char *str);
int		ft_strcmp(char *str1, char *str2);
void	flood_fill(char **tab, char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char *str, char c);
char	*ft_strrchr(char *str, char c);
int		free_matrix(char **x, int n);
char	*get_next_line(int fd);
char	*ft_strdup(char *str);
int		ft_strlen(char *str);
char	**parsing(char *arg);

#endif