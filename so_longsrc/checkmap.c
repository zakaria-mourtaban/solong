/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:30:31 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/21 21:55:43 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	floodfillcheck(int i, int j, char **mapcpy)
{
	if (mapcpy[i][j] == 1)
		return ;
	if (g_map.map[i][j] == '1')
		return ;
	if (g_map.map[i][j] == 'E')
	{
		g_map.exitfound = 1;
		return ;
	}
	if (i == 0 || j == 0 || j == g_map.width - 1 || i == g_map.height - 1)
		ft_error("map walls leak");
	mapcpy[i][j] = 1;
	floodfillcheck(i + 1, j, mapcpy);
	floodfillcheck(i, j + 1, mapcpy);
	floodfillcheck(i, j - 1, mapcpy);
	floodfillcheck(i - 1, j, mapcpy);
}

void	checkmaperror(void)
{
	int		i;
	int		j;
	char	**mapcpy;

	i = g_map.height;
	while (i > 0)
	{
		if (g_map.width != (int)ft_strlen(g_map.map[i - 1]))
			ft_error("map length error");
		i--;
	}
	mapcpy = (char **)malloc(g_map.height * sizeof(char *));
	if (mapcpy == NULL)
		ft_error("alloc error");
	j = g_map.height;
	while (j > 0)
	{
		mapcpy[j - 1] = ft_calloc(g_map.width, sizeof(int));
		j--;
	}
	floodfillcheck(g_map.spawnx, g_map.spawny, mapcpy);
	if (g_map.exitfound == 0)
		ft_error("exit unreachable");
}

int	cond(int i, int j)
{
	if (g_map.map[i][j] && !(g_map.map[i][j] == 'E' || g_map.map[i][j] == 'P'
			|| g_map.map[i][j] == 'C' || g_map.map[i][j] == '1'
			|| g_map.map[i][j] == '0'))
		return (1);
	return (0);
}

void	findmappoints(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_map.height - 1)
	{
		j = 0;
		while (j < g_map.width - 1)
		{
			if (g_map.map[i][j] && g_map.map[i][j] == 'P')
			{
				g_map.spawnx = i;
				g_map.spawny = j;
				j++;
			}
			if (g_map.map[i][j] && g_map.map[i][j] == 'C')
				g_map.collectablecounter++;
			if (g_map.map[i][j] && g_map.map[i][j] == 'E')
			{
				g_map.exitx = i;
				g_map.exity = j;
			}
			if (g_map.map[i][j] && g_map.map[i][j] == 'P' && g_map.playerfound == 1)
				ft_printf("multiple players found should error and exit");
			if (cond(i, j))
				ft_error("map has unallowed chars you should free here");
			j++;
		}
		i++;
	}
}
