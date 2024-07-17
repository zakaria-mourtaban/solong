/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 02:09:50 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/17 03:12:23 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int is_point_in_triangle(int x1, int y1, int x2, int y2, int x3, int y3, int px, int py) {
    // Compute vectors & dot products
    int v0x = x2 - x1, v0y = y2 - y1;
    int v1x = x3 - x1, v1y = y3 - y1;
    int v2x = px - x1, v2y = py - y1;

    int dot00 = v0x * v0x + v0y * v0y;
    int dot01 = v0x * v1x + v0y * v1y;
    int dot02 = v0x * v2x + v0y * v2y;
    int dot11 = v1x * v1x + v1y * v1y;
    int dot12 = v1x * v2x + v1y * v2y;

    // Compute barycentric coordinates
    double invDenom = 1.0 / (dot00 * dot11 - dot01 * dot01);
    double u = (dot11 * dot02 - dot01 * dot12) * invDenom;
    double v = (dot00 * dot12 - dot01 * dot02) * invDenom;

    // Check if point is in triangle
    return (u >= 0) && (v >= 0) && (u + v <= 1);
}

int	colorget(int i)
{
	static int	color = 16777215;

	color -= 10 + i;
	return (color);
}

int	main(void)
{
	void *mlx;
	void *mlx_win;
	t_data img;
	int i;
	int j;

	i = 0;
	j = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	while (i <= 500)
	{
		j = 0;
		while (j <= 500)
		{
			if (is_point_in_triangle(250,0,500,500,0,500,i,j))
				my_mlx_pixel_put(&img, 50 + i, 50 + j, colorget(i + j));
			j++;
			;
		}
		i++;
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}