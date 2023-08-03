/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:44:05 by sejokim           #+#    #+#             */
/*   Updated: 2023/08/03 19:51:39 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	texture_dup_check(char **tokens, t_config *config)
{
	if (ft_strcmp(tokens[0], "NO") == 0)
		config->fc_set.no_tex_set++;
	else if (ft_strcmp(tokens[0], "SO") == 0)
		config->fc_set.so_tex_set++;
	else if (ft_strcmp(tokens[0], "WE") == 0)
		config->fc_set.we_tex_set++;
	else if (ft_strcmp(tokens[0], "EA") == 0)
		config->fc_set.ea_tex_set++;
}

void	color_dup_check(char **tokens, t_config *config)
{
	if (ft_strcmp(tokens[0], "F") == 0)
		config->fc_set.floor_set++;
	else if (ft_strcmp(tokens[0], "C") == 0)
		config->fc_set.ceiling_set++;
}

void	check_duplicate(t_config *config)
{
	if (config->fc_set.no_tex_set > 1)
		parse_error("Duplicate NO texture.\n", 2);
	if (config->fc_set.so_tex_set > 1)
		parse_error("Duplicate SO texture.\n", 2);
	if (config->fc_set.we_tex_set > 1)
		parse_error("Duplicate WE texture.\n", 2);
	if (config->fc_set.ea_tex_set > 1)
		parse_error("Duplicate EA texture.\n", 2);
	if (config->fc_set.floor_set > 1)
		parse_error("Duplicate floor color.\n", 2);
	if (config->fc_set.ceiling_set > 1)
		parse_error("Duplicate ceiling color.\n", 2);
}
