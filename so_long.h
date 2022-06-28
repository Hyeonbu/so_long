/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanjeon <chanjeon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 22:50:53 by chanjeon          #+#    #+#             */
/*   Updated: 2022/06/29 07:32:52 by chanjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "get_next_line.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17

# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_ESC	53

typedef struct s_image
{
	void	*chr;
	void	*star;
	void	*land;
	void	*close;
	void	*open;
	void	*wall;
}			t_image;

typedef struct s_system
{
	t_image	image;
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		walk_cnt;
	int		col_cnt;
	int		col_num;
	char	*line;
}			t_system;

/* set_images.c */
t_image	image_initial(void *mlx);
void	put_image(t_system *s, int w, int h);
void	set_images(t_system *sys);

/* check_map.c */
void	check_wall(t_system *sys);
void	check_params(t_system *sys);
void	check_map(t_system *sys);
void	read_map(char *file, t_system *sys);

/* press_key.c */
int		press_key(int key, t_system *sys);
void	press_w(t_system *s);
void	press_a(t_system *s);
void	press_s(t_system *s);
void	press_d(t_system *s);

/* so_long.c */
int		clear_game(t_system *sys);
int		exit_game(t_system *sys);
void	error_msg(char *str);
void	system_initial(t_system *sys, char *map);
int		main(int ac, char *av[]);

#endif
