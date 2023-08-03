/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:22:15 by sejokim           #+#    #+#             */
/*   Updated: 2023/08/03 14:48:17 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_line(char *line, t_config *config)
{
	int		i;

	i = 0;
	if (is_texture(line))
		get_texture(line, config);
	else if (is_color(line))
		get_color(line, config);
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '0' || line[i] == '1')
	{
		if (config->no_tex != NULL && config->so_tex != NULL && \
		config->we_tex != NULL && config->ea_tex != NULL && \
		config->ceiling_color != -1 && config->floor_color != -1)
			config->map_started = 1;
	}
	if (config->map_started != 0)
	{
		if (line[0] == '\0' || is_map_line(line) == 0)
			parse_error("Invalid map line.\n", 2);
		else
			process_map_line(line, config);
	}
}

void	remove_next_line(char *line)
{
	while (*line)
	{
		if (*line == '\n')
		{
			*line = '\0';
			break ;
		}
		line++;
	}
}

static void	check_color(t_config *config)
{
	if (config->ceiling_color == -1 || config->floor_color == -1)
		parse_error("Invalid color line.\n", 2);
}

static void	check_texture(t_config *config)
{
	if (config->no_tex == NULL || config->so_tex == NULL || \
	config->we_tex == NULL || config->ea_tex == NULL)
		parse_error("Invalid texture line.\n", 2);
}

void	print_map(t_config *config)
{
	int	col;

	col = 0;
	while (col < config->map_cols)
	{
		printf("%s", config->map[col]);
		col++;
	}
}

void	parse_config(char *file_path, t_config *config)
{
	int		fd;
	char	*line;

	initialize_config(config);
	check_file_extension(file_path);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		parse_error("file open error.\n", 2);
	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		remove_next_line(line);
		parse_line(line, config);
		free(line);
	}
	check_color(config);
	check_texture(config);
	close(fd);
	fill_map(file_path, config);
	// print_map(config);  // 맵 출력, 실험용
}
