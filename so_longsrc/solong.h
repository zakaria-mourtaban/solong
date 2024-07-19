/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:15:43 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/19 16:19:55 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "../minilibx_linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char	**map;
	char	*filepath; // is av do not free
	int		width;
	int		height;
	int		spawnx;
	int		spawny;
	int		exitx;
	int		exity;
	int		collectablecounter;
	int		exitfound;
}			t_map;

t_map		g_map;
void		ft_error(char *msg);
void		handleinput(int ac);
int			getmapheight(char *filepath);
int			getmapwidth(char *filepath);
void		parsemap(char *filepath);

#endif