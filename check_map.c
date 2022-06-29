/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanjeon <chanjeon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 00:15:28 by chanjeon          #+#    #+#             */
/*   Updated: 2022/06/29 14:12:35 by chanjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_wall(t_system *sys)
{
	int	i;

	i = 0;
	while (i < ft_strlen(sys->line))
	{
		if (i < sys->width)
		{
			if (sys->line[i] != '1')
				error_msg("The Map should be surrounded by walls.\n");
		}
		else if (i % sys->width == 0 || i % sys->width == sys->width - 1)
		{
			if (sys->line[i] != '1')
				error_msg("The Map should be surrounded by walls.\n");
		}
		else if (i > ft_strlen(sys->line) - sys->width)
		{
			if (sys->line[i] != '1')
				error_msg("The Map should be surrounded by walls.\n");
		}
		i++;
	}
}

void	check_params(t_system *sys)
{
	int	cnt_e;
	int	cnt_p;
	int	i;

	cnt_e = 0;
	cnt_p = 0;
	i = 0;
	sys->col_num = 0;
	sys->col_cnt = 0;
	while (i++ < ft_strlen(sys->line))
	{
		if (sys->line[i] == 'E')
			cnt_e++;
		else if (sys->line[i] == 'P')
			cnt_p++;
		else if (sys->line[i] == 'C')
			sys->col_num++;
	}
	if (cnt_e <= 0)
		error_msg("The Map must have at least one exit.\n");
	if (cnt_p != 1)
		error_msg("The Map must have one starting point.\n");
	if (sys->col_num <= 0)
		error_msg("The Map must have at lest one collection.\n");
}

void	check_map(t_system *sys)
{
	if (sys->height * sys->width != ft_strlen(sys->line))
		error_msg("The Map is not rectangular.\n");
}

void	read_map(char *file, t_system *sys)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		error_msg("Failed to open File.\n");
	line = get_next_line(fd);
	sys->width = ft_strlen(line) - 1;
	sys->height = 0;
	sys->walk_cnt = 0;
	sys->line = ft_strdup(line);
	free(line);
	while (line)
	{
		sys->height++;
		line = get_next_line(fd);
		check_map(sys);
		if (line)
			sys->line = ft_strjoin(sys->line, line);
	}
	close(fd);
	check_wall(sys);
	check_params(sys);
}
