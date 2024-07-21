/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:17:16 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/21 22:17:27 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	drawpbottom(int i, int j)
{
	if (g_frame < 15)
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_frames.idlebottom1,
			(j * 32), (i * 32));
	else if (g_frame < 30)
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_frames.idlebottom2,
			(j * 32), (i * 32));
	else if (g_frame < 45)
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_frames.idlebottom1,
			(j * 32), (i * 32));
	else if (g_frame < 60)
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_frames.idlebottom2,
			(j * 32), (i * 32));
}

void	drawpleft(int i, int j)
{
	if (g_frame < 15)
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_frames.idleleft1, (j
				* 32), (i * 32));
	else if (g_frame < 30)
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_frames.idleleft2, (j
				* 32), (i * 32));
	else if (g_frame < 45)
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_frames.idleleft1, (j
				* 32), (i * 32));
	else if (g_frame < 60)
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_frames.idleleft2, (j
				* 32), (i * 32));
}

void	drawpright(int i, int j)
{
	if (g_frame < 15)
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_frames.idleright1,
			(j * 32), (i * 32));
	else if (g_frame < 30)
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_frames.idleright2,
			(j * 32), (i * 32));
	else if (g_frame < 45)
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_frames.idleright1,
			(j * 32), (i * 32));
	else if (g_frame < 60)
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_frames.idleright2,
			(j * 32), (i * 32));
}

void	drawplayer(int i, int j)
{
	if (g_map.direction == 0)
		drawpleft(i, j);
	if (g_map.direction == 1)
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_frames.idletop, (j
				* 32), (i * 32));
	if (g_map.direction == 2)
		drawpright(i, j);
	if (g_map.direction == 3)
		drawpbottom(i, j);
}

void	drawgem(int i, int j)
{
	if (g_frame < 15)
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_frames.gem0, (j
				* 32), (i * 32));
	else if (g_frame < 30)
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_frames.gem1, (j
				* 32), (i * 32));
	else if (g_frame < 45)
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_frames.gem2, (j
				* 32), (i * 32));
	else if (g_frame < 60)
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_frames.gem1, (j
				* 32), (i * 32));
}