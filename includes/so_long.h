/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:07:10 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/08 16:16:10 by tikhacha         ###   ########.fr       */
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
//# include <mlx.h>
# include "../../minilibx/mlx.h"

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		width;
	int		height;
}			t_img;

typedef struct s_mlx
{
	void		*ptr;
	void		*win;
	char		**map;
	t_img		img;
	t_player	player;
	t_rival		rival;
}				t_mlx;

typedef struct s_game_p
{
	void	*ptr;
	void	*win;
	void	*pf0;
	void	*pf1;
	void	*pf2;
	void	*pf3;
	void	*pr0;
	void	*pr1;
	void	*pr2;
	void	*pr3;
	void	*pr4;
	void	*pr5;
	void	*pr6;
	void	*pr7;
}			t_player;

typedef struct s_game_r
{
	void	*ptr;
	void	*win;
	void	*rv0;
	void	*rv1;
	void	*rv2;
	void	*rv3;
}			t_rival;

typedef struct s_game_wandg
{
	void	*ptr;
	void	*win;
	void	*w0;
	void	*w1;
	void	*g0;
	void	*g1;
	void	*g2;
	void	*g3;
	void	*g4;
	void	*g5;
	void	*g6;
}

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