/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:15:43 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/23 10:50:17 by zmourtab         ###   ########.fr       */
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
# include <time.h>
# include <unistd.h>

typedef struct s_map
{
	char		**map;
	char		*filepath;
	int			width;
	int			height;
	int			spawnx;
	int			spawny;
	int			exitx;
	int			exity;
	int			collectablecounter;
	int			collected;
	int			exitfound;
	int			direction;
	int			playerfound;
	int			collectablesreached;
	int			movecount;
}				t_map;

typedef struct s_frames
{
	void		*idleright1;
	void		*idleright2;
	void		*idleleft1;
	void		*idleleft2;
	void		*idletop;
	void		*idlebottom1;
	void		*idlebottom2;
	void		**die;
	void		*wallfill;
	void		*exit;
	void		*empty;
	void		*potion;
	void		*gem0;
	void		*gem1;
	void		*gem2;
}				t_frames;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
}				t_mlx;

extern int		g_frame;
extern t_mlx	g_mlx;
extern t_map	g_map;
extern t_frames	g_frames;

size_t			ft_strlenc(const char *s);
void			freeatexit(char *msg);
void			drawl(int i, int j);
void			drawpbottom(int i, int j);
void			drawpleft(int i, int j);
void			drawpright(int i, int j);
void			drawplayer(int i, int j);
void			drawframes(void);
int				drawlight(void);
void			drawgem(int i, int j);
void			movetop(int i, int j);
void			movebottom(int i, int j);
void			moveleft(int i, int j);
void			moveright(int i, int j);
void			moveplayer(int key);
void			maperror(int ac, char **av);
void			ft_error(char *msg);
void			handleinput(int ac);
int				getmapheight(char *filepath);
int				getmapwidth(char *filepath);
void			parsemap(char *filepath);
void			floodfillcheck(int i, int j, char **mapcpy);
void			checkmaperror(void);
void			findmappoints(void);
void			fillidle(void *mlx, int *width, int *height);
void			fillrun(void *mlx, int *width, int *height);
void			filldie(void *mlx, int *width, int *height);
void			fillwalls(void *mlx, int *width, int *height);
void			fillframes(void *mlx, int *width, int *height);
#endif