/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:07:10 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/14 19:55:13 by tikhacha         ###   ########.fr       */
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
# include <math.h>
# include "../../minilibx/mlx.h"
# include <mlx.h>

# define KEYDOWN 2
# define DARK_ORANGE 0xDC5410
# define BLUE 0x1681C9
# define REDCROSS 17
# define KEYA 0
# define KEYS 1
# define KEYD 2
# define KEYW 13
# define UPARROW 126
# define DOWNARROW 125
# define LEFTARROW 123
# define RIGHTARROW 124
# define KEYESC 53
# define S 48

/*
*int	x;
*int	y;
*/
typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

/*
*void	**pf;
*void	**pr;
*int	pfc;
*int	prc;
*/
typedef struct s_game_p
{
	void	**pf;
	void	**pr;
	void	**pl;
	int		dir;
	int		pfc;
	int		prc;
	int		plc;
}			t_player;

/*
*void	**rv;
*int	rvc;
*/
typedef struct s_game_r
{
	void	**rv;
	int		rvc;
}			t_rival;

/*
*void	**g;
*void	**w;
*int	wc;
*int	gc;
*/
typedef struct s_game_wandg
{
	void	**g;
	void	**w;
	int		wc;
	int		gc;
}			t_etc;

/*
*void	**c;
*int	wc;
*int	coins;
*int	n;
*int	custom;
*/
typedef struct s_coins
{
	void	**c;
	int		wc;
	int		coins;
	int		n;
	int		custom;
}			t_coin;

/*
*void	**d;
*int	dc;
*/
typedef struct s_doors
{
	void	**d;
	int		dc;
}			t_door;

/*
*void		*ptr;
*void		*win;
*char		**map;
*int		on_off;
*int		counter;
*int		x;
*int		y;
*int		w;
*int		h;
*t_player	p;
*t_rival	r;
*t_etc		gw;
*t_coin		c;
*t_door		d;
*/
typedef struct s_mlx
{
	void		*ptr;
	void		*win;
	char		**map;
	int			on_off;
	int			counter;
	int			x;
	int			y;
	int			w;
	int			h;
	t_player	p;
	t_rival		r;
	t_etc		gw;
	t_coin		c;
	t_door		d;
}				t_mlx;

char	*ft_substr(char *s, unsigned int start, size_t len);
void	ft_player_coord(char **map, t_point *begin);
void	game_win(t_mlx *mlx, int i, int j, char c);
void	free_vmatrix(t_mlx *mlx, void **x, int n);
void	additional_checks(char **map, char *s);
int		keypressed(int keycode, t_mlx *mlx);
void	map_size(char **map, t_mlx *size);
char	**ft_split(char const *s, char c);
int		free_strings(char **x, char *str);
int		ft_strcmp(char *str1, char *str2);
void	flood_fill(char **tab, char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char *str, char c);
char	*ft_strrchr(char *str, char c);
int		free_matrix(char **x, int n);
void	mlx_put_sprites(t_mlx *mlx);
void	mlx_put_ground(t_mlx *mlx);
void	load_sprites_3(t_mlx *mlx);
void	load_sprites_2(t_mlx *mlx);
void	load_sprites(t_mlx *mlx);
int		close_window(t_mlx *mlx);
char	*get_next_line(int fd);
void	move_right(t_mlx *mlx);
void	move_left(t_mlx *mlx);
void	move_down(t_mlx *mlx);
void	move_up(t_mlx *mlx);
void	mlx_start(t_mlx *mlx);
char	*ft_strdup(char *str);
int		ft_strlen(char *str);
char	**parsing(char *arg);
char	*ft_itoa(int n);
int		frame(int n);

#endif