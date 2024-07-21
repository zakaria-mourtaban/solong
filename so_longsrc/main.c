/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:17:47 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/22 02:03:23 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_map		g_map;
t_frames	g_frames;
t_mlx		g_mlx;
int			g_frame;

void	putmovestr(void)
{
	char	*line;
	char	*num;

	mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_frames.wallfill, 1 * 32,
		0);
	mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_frames.wallfill, 2 * 32,
		0);
	mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_frames.wallfill, 3 * 32,
		0);
	num = ft_itoa(g_map.movecount);
	line = ft_strjoin("Move count: ", num);
	mlx_string_put(g_mlx.mlx, g_mlx.mlx_win, 10, 10, 0xFFFFFF, line);
	free(line);
	free(num);
}

int	keyhook(int keycode, void *param)
{
	(void)param;
	if (keycode == 65307)
		freeatexit("");
	moveplayer(keycode);
	putmovestr();
	return (0);
}

int	gameloop(void)
{
	drawlight();
	return (0);
}

int	closewindow(void)
{
	freeatexit("");
	return (0);
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
	drawframes();
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
