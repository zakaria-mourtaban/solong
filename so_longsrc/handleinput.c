/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleinput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:44:33 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/22 01:48:03 by zmourtab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(0);
}

void	handleinput(int ac)
{
	if (ac == 1)
		freeatexit("Error\nplease provide a valid map path");
	if (ac > 2)
		freeatexit("Error\nprovide a map path\nie:./so_long/path/to/map.ber");
}

int	getmapheight(char *filepath)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		freeatexit("Error\nerror opening file");
	line = ft_get_next_line(fd);
	while (line != NULL)
	{
		i++;
		free(line);
		line = ft_get_next_line(fd);
	}
	free(line);
	close(fd);
	return (i + 1);
}

int	getmapwidth(char *filepath)
{
	int		fd;
	char	*buffer;
	int		len;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		freeatexit("Error\nerror opening file");
	buffer = ft_get_next_line(fd);
	len = ft_strlen(buffer);
	while (buffer != NULL)
	{
		free(buffer);
		buffer = ft_get_next_line(fd);
		if (buffer != NULL && len != (int)ft_strlen(buffer))
		{
			if (buffer[ft_strlen(buffer)] == '\n')
			{
				printf("%d", (int)ft_strlen(buffer));
				freeatexit("Error\nmap not rectangular");
				free(buffer);
			}
		}
	}
	free(buffer);
	return (len - 1);
}

void	parsemap(char *filepath)
{
	int		fd;
	char	*line;
	char	*buffer;

	g_map.filepath = filepath;
	if (ft_strncmp((filepath + (ft_strlen(filepath) - 4)), ".ber", 4) != 0)
		freeatexit("Error\nunsupported filetype");
	if (getmapwidth(g_map.filepath) < 5 || getmapheight(g_map.filepath) < 3)
		freeatexit("map too small");
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		freeatexit("Error\nerror opening file");
	line = ft_strdup("");
	buffer = malloc(BUFFER_SIZE + 1);
	while (read(fd, buffer, BUFFER_SIZE) != 0)
	{
		buffer[BUFFER_SIZE] = '\0';
		line = ft_strjoingnl(line, buffer);
	}
	free(buffer);
	g_map.map = ft_split(line, '\n');
	free(line);
	g_map.width = getmapwidth(g_map.filepath);
	g_map.height = getmapheight(g_map.filepath);
	close(fd);
}
