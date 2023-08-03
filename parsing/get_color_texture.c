/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:13:21 by sejokim           #+#    #+#             */
/*   Updated: 2023/08/03 14:46:54 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_texture(char *line, t_config *config)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (tokens[0] == NULL || tokens[1] == NULL || tokens[2] != NULL)
	{
		ft_split_free(tokens, 0);
		parse_error("Invalid texture line format.\n", 2);
		return ;
	}
	if (!is_valid_texture_path(tokens[1]))
	{
		ft_split_free(tokens, 0);
		return ;
	}
	if (ft_strcmp(tokens[0], "NO") == 0)
		config->no_tex = ft_strdup(tokens[1]);
	else if (ft_strcmp(tokens[0], "SO") == 0)
		config->so_tex = ft_strdup(tokens[1]);
	else if (ft_strcmp(tokens[0], "WE") == 0)
		config->we_tex = ft_strdup(tokens[1]);
	else if (ft_strcmp(tokens[0], "EA") == 0)
		config->ea_tex = ft_strdup(tokens[1]);
	ft_split_free(tokens, 0);
}

static int	convert_rgb(char *rgb_str)
{
	char	**rgb_tokens;
	int		r;
	int		g;
	int		b;

	rgb_tokens = ft_split(rgb_str, ',');
	r = ft_atoi(rgb_tokens[0]);
	g = ft_atoi(rgb_tokens[1]);
	b = ft_atoi(rgb_tokens[2]);
	ft_split_free(rgb_tokens, 0);
	return ((r << 16) | (g << 8) | b);
}

void	get_color(char *line, t_config *config)
{
	char	**tokens;
	int		color;

	tokens = ft_split(line, ' ');
	if (tokens[0] == NULL || tokens[1] == NULL || tokens[2] != NULL || \
		!is_valid_rgb(tokens[1]))
	{
		ft_split_free(tokens, 0);
		parse_error("Invalid color line format.\n", 2);
		return ;
	}
	if (ft_strcmp(tokens[0], "C") != 0 && ft_strcmp(tokens[0], "F") != 0)
	{
		ft_split_free(tokens, 0);
		parse_error("Invalid color identifier.\n", 2);
		return ;
	}
	color = convert_rgb(tokens[1]);
	if (ft_strcmp(tokens[0], "F") == 0)
		config->floor_color = color;
	else if (ft_strcmp(tokens[0], "C") == 0)
		config->ceiling_color = color;
	ft_split_free(tokens, 0);
}
