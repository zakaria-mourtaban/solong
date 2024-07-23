/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:20:10 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/23 10:53:33 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

size_t	ft_strlenc(const char *s)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != '\n')
			j++;
		i++;
	}
	return (j);
}

void	maperror(int ac, char **av)
{
	handleinput(ac);
	parsemap(av[1]);
	g_map.movecount = 0;
	g_map.exitfound = 0;
	g_map.direction = 0;
	g_map.playerfound = 0;
	g_map.collectablecounter = 0;
	g_map.collected = 0;
	g_map.collectablesreached = 0;
	findmappoints();
	checkmaperror();
	if (g_map.exitfound == 0)
		freeatexit("Error\nexit unreachable");
	if (g_map.collectablesreached != g_map.collectablecounter)
		freeatexit("Error\na collectable is unreachable");
}
