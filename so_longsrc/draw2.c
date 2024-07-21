/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:33:48 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/22 02:04:15 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	drawl(int i, int j)
{
	if (g_map.map[i][j] == '1')
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_frames.wallfill, j
			* 32, i * 32);
	if (g_map.map[i][j] == 'P')
		drawplayer(i, j);
	if (g_map.map[i][j] == 'C')
		drawgem(i, j);
	if (g_map.map[i][j] == 'E')
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_frames.exit, j * 32,
			i * 32);
	if (g_map.map[i][j] == '0')
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_frames.empty, j
			* 32, i * 32);
}

void	drawframes(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_map.height - 1)
	{
		j = 0;
		while (j < g_map.width)
		{
			drawl(i, j);
			j++;
		}
		i++;
	}
}

int	drawlight(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_map.height - 1)
	{
		j = 0;
		while (j < g_map.width)
		{
			if (g_map.map[i][j] == 'P')
				drawplayer(i, j);
			if (g_map.map[i][j] == 'C')
				drawgem(i, j);
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
