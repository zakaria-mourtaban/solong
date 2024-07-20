/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:17:47 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/20 15:54:42 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_map		g_map;
t_frames	g_frames;

void	maperror(int ac, char **av)
{
	handleinput(ac);
	parsemap(av[1]);
	findmappoints();
	checkmaperror();
}

int	main(int ac, char **av)
{
	int		width;
	int		height;
	void	*mlx;
	void	*mlx_win;

	int i, j;
	i = 0;
	maperror(ac, av);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, (g_map.width) * 32, (g_map.height - 1) * 32,
			"So_long");
	fillframes(mlx, &width, &height);
	while (i < g_map.height)
	{
		j = 0;
		while (j < g_map.width)
		{
			if (g_map.map[i][j] == '1')
				mlx_put_image_to_window(mlx, mlx_win, g_frames.wallfill, j * 32,
					i * 32);
			if (g_map.map[i][j] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, g_frames.wallbottom, j * 32,
					i * 32);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, g_frames.wallfill, 0, 0);
	mlx_loop(mlx);
	return (0);
}
