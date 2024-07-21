/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:33:48 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/21 22:35:04 by zmourtab         ###   ########.fr       */
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