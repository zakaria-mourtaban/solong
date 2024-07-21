/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:30:31 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/22 02:01:08 by zmourtab         ###   ########.fr       */
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
		freeatexit("Error\nmap walls leak");
	mapcpy[i][j] = 1;
	floodfillcheck(i + 1, j, mapcpy);
	floodfillcheck(i, j + 1, mapcpy);
	floodfillcheck(i, j - 1, mapcpy);
	floodfillcheck(i - 1, j, mapcpy);
}

void	checkmaperror(void)
{
	int		j;
	char	**mapcpy;

	mapcpy = (char **)malloc(g_map.height * sizeof(char *));
	if (mapcpy == NULL)
		freeatexit("allocation error");
	j = g_map.height;
	while (j > 0)
	{
		mapcpy[j - 1] = ft_calloc(g_map.width, sizeof(int));
		j--;
	}
	floodfillcheck(g_map.spawnx, g_map.spawny, mapcpy);
	j = g_map.height - 1;
	while (j >= 0)
		free(mapcpy[j--]);
	free(mapcpy);
}

int	cond(int i, int j)
{
	if (g_map.map[i][j] && !(g_map.map[i][j] == 'E' || g_map.map[i][j] == 'P'
			|| g_map.map[i][j] == 'C' || g_map.map[i][j] == '1'
			|| g_map.map[i][j] == '0'))
		return (1);
	return (0);
}

void	logic(int *i, int *j)
{
	if (g_map.map[*i][*j] && g_map.map[*i][*j] == 'P')
	{
		g_map.spawnx = *i;
		g_map.spawny = *j;
		g_map.playerfound = 1;
		(*j)++;
	}
	if (g_map.map[*i][*j] && g_map.map[*i][*j] == 'E')
	{
		g_map.exitx = *i;
		g_map.exity = *j;
	}
}

void	findmappoints(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_map.height - 1)
	{
		j = 0;
		while (j < g_map.width)
		{
			if (g_map.map[i][j] && g_map.map[i][j] == 'C')
				g_map.collectablecounter++;
			if (cond(i, j))
				freeatexit("Error\nunallowed chars");
			logic(&i, &j);
			j++;
			if (g_map.map[i][j] && g_map.map[i][j] == 'P'
				&& g_map.playerfound == 1)
				freeatexit("Error\nmultiple players found");
		}
		i++;
	}
}
