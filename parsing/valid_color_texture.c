/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_color_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:57:30 by sejokim           #+#    #+#             */
/*   Updated: 2023/08/03 19:49:45 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_color(char *line, t_config *config)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens || !tokens[0])
	{
		ft_split_free(tokens, 0);
		return (0);
	}
	color_dup_check(tokens, config);
	if (ft_strcmp(tokens[0], "F") == 0 || ft_strcmp(tokens[0], "C") == 0)
	{
		ft_split_free(tokens, 0);
		return (1);
	}
	return (0);
}

int	is_texture(char *line, t_config *config)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens || !tokens[0])
	{
		ft_split_free(tokens, 0);
		return (0);
	}
	texture_dup_check(tokens, config);
	if (ft_strcmp(tokens[0], "NO") == 0 || ft_strcmp(tokens[0], "SO") == 0 \
	|| ft_strcmp(tokens[0], "WE") == 0 || ft_strcmp(tokens[0], "EA") == 0)
	{
		ft_split_free(tokens, 0);
		return (1);
	}
	return (0);
}

int	is_valid_texture_path(char *path)
{
	int	len;
	int	fd;

	len = ft_strlen(path);
	if (len < 5)
	{
		parse_error("Invalid texture path.\n", 2);
		return (0);
	}
	if (ft_strcmp(&path[len - 4], ".xpm") != 0)
	{
		parse_error("Invalid texture file extension.\n", 2);
		return (0);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		parse_error("Cannot open .xpm file.\n", 2);
		return (0);
	}
	close(fd);
	return (1);
}

int	is_valid_rgb(char *rgb_str)
{
	char	**rgb_tokens;
	int		i;
	int		rgb_val;

	rgb_tokens = ft_split(rgb_str, ',');
	i = 0;
	while (rgb_tokens[i])
	{
		rgb_val = ft_atoi(rgb_tokens[i]);
		if (!my_isdigit(rgb_tokens[i]) || (rgb_val < 0 || rgb_val > 255) || \
		ft_strlen(rgb_tokens[i]) > 3)
		{
			ft_split_free(rgb_tokens, 0);
			parse_error("Invalid RGB value.\n", 2);
		}
		i++;
	}
	if (i != 3)
	{
		ft_split_free(rgb_tokens, 0);
		parse_error("Invalid RGB value.\n", 2);
	}
	ft_split_free(rgb_tokens, 0);
	return (1);
}
