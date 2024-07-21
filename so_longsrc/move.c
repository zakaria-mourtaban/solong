/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:16:06 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/21 22:16:17 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	movetop(int i, int j)
{
	if (g_map.map[i - 1][j] == 'C')
		g_map.collected++;
	if (g_map.map[i - 1][j] == 'E'
		&& g_map.collectablecounter == g_map.collected)
		exit(0);
	if (g_map.map[i - 1][j] != '1' && g_map.map[i - 1][j] != 'E')
	{
		g_map.map[i][j] = '0';
		g_map.map[i - 1][j] = 'P';
	}
	printf("%d\n", g_map.collected);
	g_map.direction = 1;
}
void	movebottom(int i, int j)
{
	if (g_map.map[i + 1][j] == 'C')
		g_map.collected++;
	if (g_map.map[i + 1][j] == 'E'
		&& g_map.collectablecounter == g_map.collected)
		exit(0);
	if (g_map.map[i + 1][j] != '1' && g_map.map[i + 1][j] != 'E')
	{
		g_map.map[i][j] = '0';
		g_map.map[i + 1][j] = 'P';
	}
	printf("%d\n", g_map.collected);
	g_map.direction = 3;
}
void	moveleft(int i, int j)
{
	if (g_map.map[i][j - 1] == 'C')
		g_map.collected++;
	if (g_map.map[i][j - 1] == 'E'
		&& g_map.collectablecounter == g_map.collected)
		exit(0);
	if (g_map.map[i][j - 1] != '1' && g_map.map[i][j - 1] != 'E')
	{
		g_map.map[i][j] = '0';
		g_map.map[i][j - 1] = 'P';
	}
	printf("%d\n", g_map.collected);
	g_map.direction = 0;
}
void	moveright(int i, int j)
{
	if (g_map.map[i][j + 1] == 'C')
		g_map.collected++;
	if (g_map.map[i][j + 1] == 'E'
		&& g_map.collectablecounter == g_map.collected)
		exit(0);
	if (g_map.map[i][j + 1] != '1' && g_map.map[i][j + 1] != 'E')
	{
		g_map.map[i][j] = '0';
		g_map.map[i][j + 1] = 'P';
	}
	printf("%d\n", g_map.collected);
	g_map.direction = 2;
}

void	moveplayer(int key)
{
	int	i;
	int	j;
	int	l;

	l = 0;
	i = 0;
	while (i < g_map.height && l == 0)
	{
		j = 0;
		while (j < g_map.width && l == 0)
		{
			if (g_map.map[i][j] == 'P')
				l = 1;
			j++;
		}
		i++;
	}
	if (key == 97)
		moveleft(i - 1, j - 1);
	if (key == 119)
		movetop(i - 1, j - 1);
	if (key == 100)
		moveright(i - 1, j - 1);
	if (key == 115)
		movebottom(i - 1, j - 1);
}
