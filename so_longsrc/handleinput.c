/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleinput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourtab <zakariamourtaban@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:44:33 by zmourtab          #+#    #+#             */
/*   Updated: 2024/07/19 17:53:55 by zmourtab         ###   ########.fr       */
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
		ft_error("please provide a valid map path");
	if (ac > 2)
		ft_error("please only proved a map path\nie:./so_long/path/to/map.ber");
}

int	getmapheight(char *filepath)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		ft_error("error opening file");
	line = ft_get_next_line(fd);
	while (line != NULL)
	{
		i++;
		line = ft_get_next_line(fd);
	}
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
		ft_error("error opening file");
	buffer = ft_get_next_line(fd);
	len = ft_strlen(buffer);
	while (buffer != NULL)
		buffer = ft_get_next_line(fd);
	return (len - 1);
}

void	parsemap(char *filepath)
{
	int		fd;
	char	*line;
	char	*buffer;

	g_map.filepath = filepath;
	if (ft_strncmp((filepath + (ft_strlen(filepath) - 4)), ".ber", 4) != 0)
		ft_error("unsupported filetype");
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		ft_error("error opening file");
	line = ft_strdup("");
	buffer = malloc(BUFFER_SIZE + 1);
	while (read(fd, buffer, BUFFER_SIZE) != 0)
	{
		buffer[BUFFER_SIZE] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	g_map.map = ft_split(line, '\n');
	close(fd);
	g_map.exitfound = 0;
	g_map.width = getmapwidth(filepath);
	g_map.height = getmapheight(filepath);
}
