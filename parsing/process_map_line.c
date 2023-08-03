/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 19:04:42 by sejokim           #+#    #+#             */
/*   Updated: 2023/08/01 17:40:47 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void	process_map_line(char *line, t_config *config)
// {
// 	int	i;
// 	int	len;

// 	i = 0;
// 	len = ft_strlen(line);
// 	if (line[0] == '\0')
// 		parse_error("Invalid map line: contains empty line.\n", 2);
// 	config->map_rows += 1;
// 	if (len > config->map_cols)
// 		config->map_cols = len;
// }

void	process_map_line(char *line, t_config *config)
{
	int	len;
	int	i;

	i = 0;
	if (is_empty_line(line))
		parse_error("Invalid map line: contains empty line.\n", 2);
	len = ft_strlen(line);
	while (i < len)
	{
		if (ft_strchr("NEWS", line[i]) != NULL)
		{
			if (config->news_flag == 1)
				parse_error("Invalid map : News flag is duplicated.\n", 2);
			else
				config->news_flag = 1;
		}
		i++;
	}
	config->map_cols += 1;
	if (len > config->map_rows)
		config->map_rows = len;
}

void	fill_map(char *file_path, t_config *config)
{
	int		fd;
	int		col;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		parse_error("File open failed.\n", 2);
	config->map = (char **)malloc(sizeof(char *) * config->map_cols);
	col = 0;
	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (is_map_line(line))
		{
			config->map[col] = ft_strdup(line);
			col++;
		}
		free(line);
	}
	close(fd);
}
