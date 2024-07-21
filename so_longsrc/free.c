/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 00:16:51 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/22 02:05:34 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	free1(void)
{
	if (g_frames.empty != NULL)
		mlx_destroy_image(g_mlx.mlx, g_frames.empty);
	if (g_frames.exit != NULL)
		mlx_destroy_image(g_mlx.mlx, g_frames.exit);
	if (g_frames.wallfill != NULL)
		mlx_destroy_image(g_mlx.mlx, g_frames.wallfill);
	if (g_frames.die && g_frames.die[0] != NULL)
		mlx_destroy_image(g_mlx.mlx, g_frames.die[0]);
	if (g_frames.die && g_frames.die[1] != NULL)
		mlx_destroy_image(g_mlx.mlx, g_frames.die[1]);
	if (g_frames.die && g_frames.die[2] != NULL)
		mlx_destroy_image(g_mlx.mlx, g_frames.die[2]);
	if (g_frames.die && g_frames.die[3] != NULL)
		mlx_destroy_image(g_mlx.mlx, g_frames.die[3]);
	if (g_frames.die && g_frames.die[4] != NULL)
		mlx_destroy_image(g_mlx.mlx, g_frames.die[4]);
	if (g_frames.die && g_frames.die[5] != NULL)
		mlx_destroy_image(g_mlx.mlx, g_frames.die[5]);
	if (g_frames.die && g_frames.die[6] != NULL)
		mlx_destroy_image(g_mlx.mlx, g_frames.die[6]);
}

void	free2(void)
{
	int	i;

	i = 0;
	if (g_mlx.mlx != NULL && g_mlx.mlx_win != NULL)
		mlx_destroy_window(g_mlx.mlx, g_mlx.mlx_win);
	if (g_mlx.mlx != NULL)
		mlx_loop_end(g_mlx.mlx);
	while (g_map.map != NULL && g_map.map[i] != NULL)
	{
		free(g_map.map[i]);
		i++;
	}
	if (g_map.map != NULL)
		free(g_map.map);
	if (g_frames.gem0 != NULL)
		mlx_destroy_image(g_mlx.mlx, g_frames.gem0);
	if (g_frames.gem1 != NULL)
		mlx_destroy_image(g_mlx.mlx, g_frames.gem1);
	if (g_frames.gem2 != NULL)
		mlx_destroy_image(g_mlx.mlx, g_frames.gem2);
	if (g_frames.potion != NULL)
		mlx_destroy_image(g_mlx.mlx, g_frames.potion);
}

void	freeatexit(char *msg)
{
	free1();
	free2();
	if (g_frames.die)
		free(g_frames.die);
	if (g_frames.idlebottom1 != NULL)
		mlx_destroy_image(g_mlx.mlx, g_frames.idlebottom1);
	if (g_frames.idlebottom2 != NULL)
		mlx_destroy_image(g_mlx.mlx, g_frames.idlebottom2);
	if (g_frames.idleleft1 != NULL)
		mlx_destroy_image(g_mlx.mlx, g_frames.idleleft1);
	if (g_frames.idleleft2 != NULL)
		mlx_destroy_image(g_mlx.mlx, g_frames.idleleft2);
	if (g_frames.idleright1 != NULL)
		mlx_destroy_image(g_mlx.mlx, g_frames.idleright1);
	if (g_frames.idleright2 != NULL)
		mlx_destroy_image(g_mlx.mlx, g_frames.idleright2);
	if (g_frames.idletop != NULL)
		mlx_destroy_image(g_mlx.mlx, g_frames.idletop);
	if (g_mlx.mlx != NULL)
		mlx_destroy_display(g_mlx.mlx);
	free(g_mlx.mlx);
	ft_error(msg);
}
