/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanjeon <chanjeon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 01:04:35 by chanjeon          #+#    #+#             */
/*   Updated: 2022/06/29 03:53:03 by chanjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	press_key(int key, t_system *sys)
{
	if (key == KEY_W)
		press_w(sys);
	if (key == KEY_A)
		press_a(sys);
	if (key == KEY_S)
		press_s(sys);
	if (key == KEY_D)
		press_d(sys);
	if (key == KEY_ESC)
		exit_game(sys);
	return (0);
}

void	press_w(t_system *s)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(s->line))
	{
		if (s->line[i] == 'P')
			break ;
	}
	if (s->line[i - s->width] == 'C')
		s->col_cnt++;
	if (s->line[i - s->width] == 'E' && s->col_num == s->col_cnt)
		clear_game(s);
	else if (s->line[i - s->width] != '1' && s->line[i - s->width] != 'E')
	{
		s->line[i] = '0';
		s->line[i - s->width] = 'P';
		s->walk_cnt++;
		printf("%d\n", s->walk_cnt);
		set_images(s);
	}
}

void	press_a(t_system *s)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(s->line))
	{
		if (s->line[i] == 'P')
			break ;
	}
	if (s->line[i - 1] == 'C')
		s->col_cnt++;
	if (s->line[i - 1] == 'E' && s->col_num == s->col_cnt)
		clear_game(s);
	else if (s->line[i - 1] != '1' && s->line[i - 1] != 'E')
	{
		s->line[i] = '0';
		s->line[i - 1] = 'P';
		s->walk_cnt++;
		printf("%d\n", s->walk_cnt);
		set_images(s);
	}
}

void	press_s(t_system *s)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(s->line))
	{
		if (s->line[i] == 'P')
			break ;
	}
	if (s->line[i + s->width] == 'C')
		s->col_cnt++;
	if (s->line[i + s->width] == 'E' && s->col_num == s->col_cnt)
		clear_game(s);
	else if (s->line[i + s->width] != '1' && s->line[i + s->width] != 'E')
	{
		s->line[i] = '0';
		s->line[i + s->width] = 'P';
		s->walk_cnt++;
		printf("%d\n", s->walk_cnt);
		set_images(s);
	}
}

void	press_d(t_system *s)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(s->line))
	{
		if (s->line[i] == 'P')
			break ;
	}
	if (s->line[i + 1] == 'C')
		s->col_cnt++;
	if (s->line[i + 1] == 'E' && s->col_num == s->col_cnt)
		clear_game(s);
	else if (s->line[i + 1] != '1' && s->line[i + 1] != 'E')
	{
		s->line[i] = '0';
		s->line[i + 1] = 'P';
		s->walk_cnt++;
		printf("%d\n", s->walk_cnt);
		set_images(s);
	}
}
