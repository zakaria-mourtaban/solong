/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:17:47 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/21 22:16:59 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_map		g_map;
t_frames	g_frames;
t_mlx		g_mlx;
int			g_frame;

void	maperror(int ac, char **av)
{
	handleinput(ac);
	parsemap(av[1]);
	findmappoints();
	checkmaperror();
}



int	drawframes(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_map.height - 1)
	{
		j = 0;
		while (j < g_map.width)
		{
			if (g_map.map[i][j] == '1')
				mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win,
					g_frames.wallfill, j * 32, i * 32);
			if (g_map.map[i][j] == 'P')
				drawplayer(i, j);
			if (g_map.map[i][j] == 'C')
				drawgem(i, j);
			if (g_map.map[i][j] == 'E')
				mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_frames.exit,
					j * 32, i * 32);
			if (g_map.map[i][j] == '0')
				mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win,
					g_frames.empty, j * 32, i * 32);
			j++;
		}
		i++;
	}
	usleep(17 * 1000);
	g_frame++;
	if (g_frame == 61)
		g_frame = 0;
	return (0);
}

int	keyhook(int keycode, void *param)
{
	(void)param;
	if (keycode == 65307)
	{
		ft_printf("should be freeing all memory");
		exit(0);
	}
	moveplayer(keycode);
	return (0);
}

int	gameloop(void)
{
	drawframes();
	return (0);
}

int	closewindow(void)
{
	ft_printf("should be freeing and exiting");
	exit(0);
}

int	main(int ac, char **av)
{
	int	width;
	int	height;

	maperror(ac, av);
	g_mlx.mlx = mlx_init();
	g_mlx.mlx_win = mlx_new_window(g_mlx.mlx, (g_map.width) * 32, (g_map.height
				- 1) * 32, "So_long");
	fillframes(g_mlx.mlx, &width, &height);
	mlx_hook(g_mlx.mlx_win, 17, 0, closewindow, NULL);
	mlx_key_hook(g_mlx.mlx_win, keyhook, NULL);
	mlx_loop_hook(g_mlx.mlx, gameloop, NULL);
	mlx_loop(g_mlx.mlx);
	return (0);
}

// mlx_put_image_to_window(mlx, mlx_win, g_frames.wallfill, 0, 0);
// while (i < g_map.height)
// {
// 	j = 0;
// 	while (j < g_map.width)
// 	{
// if (g_map.map[i][j] == '1')
// 	mlx_put_image_to_window(mlx, mlx_win, g_frames.wallfill, j * 32,
// 		i * 32);
// 		if (g_map.map[i][j] == 'P')
// 			mlx_put_image_to_window(mlx, mlx_win, g_frames.wallbottom, j * 32,
// 				i * 32);
// 		j++;
// 	}
// 	i++;
// }
