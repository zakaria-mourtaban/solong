/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillframes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:14:38 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/20 15:52:23 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	fillidle(void *mlx, int *width, int *height)
{
	g_frames.idle1 = mlx_xpm_file_to_image(mlx, "./frames/idle/0.xpm", width,
			height);
	g_frames.idle2 = mlx_xpm_file_to_image(mlx, "./frames/idle/1.xpm", width,
			height);
}

void	fillrun(void *mlx, int *width, int *height)
{
	g_frames.run = (void **)malloc(sizeof(void *) * 8);
	g_frames.run[0] = mlx_xpm_file_to_image(mlx, "./frames/run/0.xpm", width,
			height);
	g_frames.run[1] = mlx_xpm_file_to_image(mlx, "./frames/run/1.xpm", width,
			height);
	g_frames.run[2] = mlx_xpm_file_to_image(mlx, "./frames/run/2.xpm", width,
			height);
	g_frames.run[3] = mlx_xpm_file_to_image(mlx, "./frames/run/3.xpm", width,
			height);
	g_frames.run[4] = mlx_xpm_file_to_image(mlx, "./frames/run/4.xpm", width,
			height);
	g_frames.run[5] = mlx_xpm_file_to_image(mlx, "./frames/run/5.xpm", width,
			height);
	g_frames.run[6] = mlx_xpm_file_to_image(mlx, "./frames/run/6.xpm", width,
			height);
	g_frames.run[7] = mlx_xpm_file_to_image(mlx, "./frames/run/7.xpm", width,
			height);
}

void	filldie(void *mlx, int *width, int *height)
{
	g_frames.die = (void **)malloc(sizeof(void *) * 7);
	g_frames.die[0] = mlx_xpm_file_to_image(mlx, "./frames/die/0.xpm", width,
			height);
	g_frames.die[1] = mlx_xpm_file_to_image(mlx, "./frames/die/1.xpm", width,
			height);
	g_frames.die[2] = mlx_xpm_file_to_image(mlx, "./frames/die/2.xpm", width,
			height);
	g_frames.die[3] = mlx_xpm_file_to_image(mlx, "./frames/die/3.xpm", width,
			height);
	g_frames.die[4] = mlx_xpm_file_to_image(mlx, "./frames/die/4.xpm", width,
			height);
	g_frames.die[5] = mlx_xpm_file_to_image(mlx, "./frames/die/5.xpm", width,
			height);
	g_frames.die[6] = mlx_xpm_file_to_image(mlx, "./frames/die/6.xpm", width,
			height);
}

void	fillwalls(void *mlx, int *width, int *height)
{
	g_frames.wallbottom = mlx_xpm_file_to_image(mlx,
			"./frames/walls/wallbottom.xpm", width, height);
	g_frames.walltop = mlx_xpm_file_to_image(mlx, "./frames/walls/walltop.xpm",
			width, height);
	g_frames.wallright = mlx_xpm_file_to_image(mlx,
			"./frames/walls/wallright.xpm", width, height);
	g_frames.wallleft = mlx_xpm_file_to_image(mlx,
			"./frames/walls/wallleft.xpm", width, height);
	g_frames.wallfill = mlx_xpm_file_to_image(mlx,
			"./frames/walls/wallfill.xpm", width, height);
	g_frames.walltopleft = mlx_xpm_file_to_image(mlx,
			"./frames/walls/walltopleft.xpm", width, height);
	g_frames.walltopright = mlx_xpm_file_to_image(mlx,
			"./frames/walls/walltopright.xpm", width, height);
	g_frames.wallbottomleft = mlx_xpm_file_to_image(mlx,
			"./frames/walls/wallbottomleft.xpm", width, height);
	g_frames.wallbottomright = mlx_xpm_file_to_image(mlx,
			"./frames/walls/wallbottomright.xpm", width, height);
}

void	fillframes(void *mlx, int *width, int *height)
{
	fillidle(mlx, width, height);
	filldie(mlx, width, height);
	fillrun(mlx, width, height);
	fillwalls(mlx, width, height);
}
