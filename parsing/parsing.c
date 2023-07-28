/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:22:15 by sejokim           #+#    #+#             */
/*   Updated: 2023/07/26 19:10:10 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_rgb_range(char *rgb)
{
	char	**rgb_value;
	int		i;

	rgb_value = ft_split(rgb, ',');
	i = 0;
	while (rgb_value[i] != NULL)
	{
		if (ft_atoi(rgb_value[i]) < 0 || ft_atoi(rgb_value[i]) > 255)
		{
			ft_split_free(rgb_value, i);
			return (0);
		}
		i++;
	}
	ft_split_free(rgb_value, i);
	return (1);
}

void add_line_to_map(char *line, t_config *config)
{
    int i;
    char **new_map;
    int line_length;

    new_map = (char **)malloc(sizeof(char *) * (config->map_rows + 2));  // One more space for NULL
    i = 0;
    if (new_map == NULL)
        exit(1);
    while (i < config->map_rows)
    {
        new_map[i] = config->map[i];
        i++;
    }
    new_map[i] = ft_strdup(line);  // Add new line before incrementing map_rows
    if (new_map[i] == NULL)
        exit(1);
    new_map[i + 1] = NULL;  // Set next pointer to NULL
    if (config->map != NULL)
        free(config->map);  // Only free old map, not each line
    config->map = new_map;  // Switch to new map
    config->map_rows += 1;  // Only increment map_rows now
    line_length = ft_strlen(line);
    if (line_length > config->map_cols)
        config->map_cols = line_length;
}

void	parse_line(char *line, t_config *config)
{
	char	**tokens;
	int		i;

	tokens = ft_split(line, ' ');
	if (tokens[0] == NULL)
	{
		ft_split_free(tokens, 0);
		return ;
	}
	if (ft_strcmp(tokens[0], "NO") != 0 && ft_strcmp(tokens[0], "SO") != 0 && \
		ft_strcmp(tokens[0], "WE") != 0 && ft_strcmp(tokens[0], "EA") != 0 && \
		ft_strcmp(tokens[0], "F") != 0 && ft_strcmp(tokens[0], "C") != 0)
	{
		if (ft_strlen(line) > 0)
			add_line_to_map(line, config);
		else
		{
			write(2, "Error\nInvalid line\n", 19);
			exit(1);
		}
	}
	else
	{
		if (ft_strcmp(tokens[0], "NO") == 0 && tokens[1] != NULL)
			ft_strlcpy(config->north_texture, tokens[1], MAX_PATH_LEN);
		else if (ft_strcmp(tokens[0], "SO") == 0 && tokens[1] != NULL)
			ft_strlcpy(config->south_texture, tokens[1], MAX_PATH_LEN);
		else if (ft_strcmp(tokens[0], "WE") == 0 && tokens[1] != NULL)
			ft_strlcpy(config->west_texture, tokens[1], MAX_PATH_LEN);
		else if (ft_strcmp(tokens[0], "EA") == 0 && tokens[1] != NULL)
			ft_strlcpy(config->east_texture, tokens[1], MAX_PATH_LEN);
		else if (ft_strcmp(tokens[0], "F") == 0 && tokens[1] != NULL)
		{
			if (check_rgb_range(tokens[1]))
				ft_strlcpy(config->floor_color, tokens[1], MAX_RGB_LEN);
			else
			{
				printf("Error\nInvalid floor color value\n");
				exit(1);
			}
		}
		else if (ft_strcmp(tokens[0], "C") == 0 && tokens[1] != NULL)
		{
			if (check_rgb_range(tokens[1]))
				ft_strlcpy(config->ceiling_color, tokens[1], MAX_RGB_LEN);
			else
			{
				printf("Error\nInvalid ceiling color value\n");
				exit(1);
			}
		}
	}
	if (tokens[0] != NULL && (ft_strcmp(tokens[0], "NO") != 0 || \
		ft_strcmp(tokens[0], "SO") != 0 || ft_strcmp(tokens[0], "WE") != 0 || \
		ft_strcmp(tokens[0], "EA") != 0 || ft_strcmp(tokens[0], "F") != 0 || \
		ft_strcmp(tokens[0], "C") != 0) && ft_strlen(line) > 0)
	{
		printf("Error\nInvalid first character in line\n");
		exit(1);
	}
	i = 0;
	while (tokens[i] != NULL)
		i++;
	ft_split_free(tokens, i);
}

void	check_file_extension(char *file_path)
{
	int	len;

	len = ft_strlen(file_path);
	if (len < 7 || ft_strcmp(file_path + len - 6, ".cub3d") != 0)
	{
		printf("Error\nInvalid file extension\n");
		exit(1);
	}
}

static void	initialize_config(t_config *config)
{
	config->map = NULL;
	config->map_rows = 0;
	config->map_cols = 0;
	config->north_texture[0] = '\0';
	config->south_texture[0] = '\0';
	config->west_texture[0] = '\0';
	config->east_texture[0] = '\0';
	config->floor_color[0] = '\0';
	config->ceiling_color[0] = '\0';
}

t_config	parse_config(char *file_path)
{
	int			fd;
	char		*line;
	int			ret;
	t_config	config;

	initialize_config(&config);
	ret = 1;
	check_file_extension(file_path);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		printf("\n");
		perror("Failed to open file");
		exit(1);
	}
	while (42)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		parse_line(line, &config);
		free(line);
	}
	close(fd);
	return (config);
}
