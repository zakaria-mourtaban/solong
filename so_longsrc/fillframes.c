/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillframes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:14:38 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/21 22:14:07 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	fillidle(void *mlx, int *width, int *height)
{
	g_frames.idleright1 = mlx_xpm_file_to_image(mlx, "./frames/idleright/0.xpm",
			width, height);
	g_frames.idleright2 = mlx_xpm_file_to_image(mlx, "./frames/idleright/1.xpm",
			width, height);
	g_frames.idleleft1 = mlx_xpm_file_to_image(mlx, "./frames/idleleft/0.xpm",
			width, height);
	g_frames.idleleft2 = mlx_xpm_file_to_image(mlx, "./frames/idleleft/1.xpm",
			width, height);
	g_frames.idlebottom1 = mlx_xpm_file_to_image(mlx,
			"./frames/idlebottom/0.xpm", width, height);
	g_frames.idlebottom2 = mlx_xpm_file_to_image(mlx,
			"./frames/idlebottom/1.xpm", width, height);
	g_frames.idletop = mlx_xpm_file_to_image(mlx, "./frames/idletop/0.xpm",
			width, height);
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
	g_frames.wallfill = mlx_xpm_file_to_image(mlx,
			"./frames/walls/wallfill.xpm", width, height);
	g_frames.exit = mlx_xpm_file_to_image(mlx, "./frames/exit.xpm", width,
			height);
}

void	fillframes(void *mlx, int *width, int *height)
{
	fillidle(mlx, width, height);
	filldie(mlx, width, height);
	fillwalls(mlx, width, height);
	g_frames.gem0 = mlx_xpm_file_to_image(mlx, "./frames/collectable/gem0.xpm",
			width, height);
	g_frames.gem1 = mlx_xpm_file_to_image(mlx, "./frames/collectable/gem1.xpm",
			width, height);
	g_frames.gem2 = mlx_xpm_file_to_image(mlx, "./frames/collectable/gem2.xpm",
			width, height);
	g_frames.empty = mlx_xpm_file_to_image(mlx, "./frames/empty.xpm",
			width, height);
}
