/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:20:10 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/22 00:58:17 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

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
	findmappoints();
	checkmaperror();
	if (g_map.exitfound == 0)
		freeatexit("Error\nexit unreachable");
}
