/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:17:47 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/19 19:28:18 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	floodfillcheck(int i, int j)
{
	if (g_map.map[i][j] == '1')
		return ;
	if (g_map.map[i][j] == 'E')
	{
		g_map.exitfound = 1;
		return ;
	}
	if (i == 0 || j == 0 || j == g_map.width - 1 || i == g_map.height - 1)
		ft_error("map walls leak");
	printf("i:%d,j:%d\n", i, j);
	floodfillcheck(i - 1, j);
	floodfillcheck(i + 1, j);
	floodfillcheck(i, j - 1);
	floodfillcheck(i, j + 1);
}

void	checkmaperror(void)
{
	int	i;

	i = g_map.height;
	while (i > 0)
	{
		if (g_map.width != ft_strlen(g_map.map[i - 1]))
			ft_error("map length error");
		i--;
	}
	floodfillcheck(g_map.spawnx, g_map.spawny);
	if (g_map.exitfound == 0)
		ft_error("exit unreachable");
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
			// printf("i:%d,j:%d\n", i, j);
			if (g_map.map[i][j] && g_map.map[i][j] == 'P')
			{
				g_map.spawnx = i;
				g_map.spawny = j;
			}
			if (g_map.map[i][j] && g_map.map[i][j] == 'E')
			{
				g_map.exitx = i;
				g_map.exity = j;
			}
			if (g_map.map[i][j] && !(g_map.map[i][j] == 'E'
					|| g_map.map[i][j] == 'P' || g_map.map[i][j] == 'C'
					|| g_map.map[i][j] == '1' || g_map.map[i][j] == '0'))
				ft_error("map has unallowed chars you should free here");
			j++;
		}
		i++;
	}
}

void	print_strings(char **str_array)
{
	// Iterate through the array until we encounter a NULL pointer
	for (int i = 0; str_array[i] != NULL; i++)
	{
		printf("%s\n", str_array[i]);
	}
}

int	main(int ac, char **av)
{
	handleinput(ac);
	parsemap(av[1]);
	findmappoints();
	checkmaperror();
	return (0);
}
