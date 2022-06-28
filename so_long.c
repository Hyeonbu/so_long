/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanjeon <chanjeon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 23:45:44 by chanjeon          #+#    #+#             */
/*   Updated: 2022/06/29 08:17:44 by chanjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clear_game(t_system *sys)
{
	sys->walk_cnt++;
	printf("%s %d\n", "You cleard the game.\nTotal steps :", sys->walk_cnt);
	exit(0);
}

int	exit_game(t_system *sys)
{
	mlx_destroy_window(sys->mlx, sys->win);
	exit(0);
}

void	error_msg(char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	exit(1);
}

void	system_initial(t_system *sys, char *map)
{
	sys->mlx = mlx_init();
	sys->image = image_initial(sys->mlx);
	read_map(map, sys);
	check_map(sys);
	sys->win = mlx_new_window(sys->mlx, sys->width * 64, \
			sys->height * 64, "so_long");
	set_images(sys);
}

int	main(int ac, char *av[])
{
	t_system	*sys;

	if (ac != 2)
		error_msg("Map not found.\n");
	sys = malloc(sizeof(t_system));
	system_initial(sys, av[1]);
	mlx_hook(sys->win, X_EVENT_KEY_PRESS, 0, &press_key, sys);
	mlx_hook(sys->win, X_EVENT_KEY_EXIT, 0, &exit_game, sys);
	mlx_loop(sys->mlx);
	return (0);
}
