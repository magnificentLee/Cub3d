/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:06:57 by jeongmil          #+#    #+#             */
/*   Updated: 2023/08/03 19:50:20 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initialize_config(t_config *config)
{
	config->map = NULL;
	config->map_rows = 0;
	config->map_cols = 0;
	config->no_tex = NULL;
	config->so_tex = NULL;
	config->we_tex = NULL;
	config->ea_tex = NULL;
	config->floor_color = -1;
	config->ceiling_color = -1;
	config->map_started = 0;
	config->news_flag = 0;
	config->fc_set.no_tex_set = 0;
	config->fc_set.so_tex_set = 0;
	config->fc_set.ea_tex_set = 0;
	config->fc_set.we_tex_set = 0;
	config->fc_set.floor_set = 0;
	config->fc_set.ceiling_set = 0;
}

void	set_player_pos(t_config *config)
{
	int	i;
	int	j;

	i = 0;
	while (config->map[i])
	{
		j = 0;
		while (config->map[i][j])
		{
			if (config->map[i][j] == 'W' || config->map[i][j] == 'E' \
			|| config->map[i][j] == 'S' || config->map[i][j] == 'N')
			{
				config->r_pos.posX = j + 0.501;
				config->r_pos.posY = i + 0.501;
			}
			j++;
		}
		i++;
	}
}

void	news_check(t_config *config)
{
	int	garo;
	int	sero;
	int	flag;

	flag = 0;
	sero = 0;
	while (sero < config->map_cols)
	{
		garo = 0;
		while (garo < config->map_rows)
		{
			if (config->map[sero][garo] == 'N' || config->map[sero][garo] == 'E'\
			|| config->map[sero][garo] == 'W' || config->map[sero][garo] == 'S')
				flag = 1;
			garo++;
		}
		sero++;
	}
	if (flag == 0)
		parse_error("No player position.\n", 2);
}

void	parsing_cub(char *file_path, t_config *config)
{
	parse_config(file_path, config);
	news_check(config);
	check_duplicate(config);
	// map_check(config);
	config->win_rows = TEX_WIDTH / SIZEVALUE * config->map_rows;
	config->win_cols = TEX_HEIGH / SIZEVALUE * config->map_cols;
	set_player_pos(config);
}

void	initialize(t_config *config, char **av)
{
	int	i;

	i = 0;
	initialize_config(config);
	parsing_cub(av[1], config);
	config->mlx = mlx_init();
	config->buf = (int **)malloc(sizeof (int *) * config->win_cols);
	if (config->buf == NULL)
		exit(0);
	i = 0;
	while (i < config->win_cols)
	{
		config->buf[i] = (int *)malloc(sizeof(int) * config->win_rows);
		if (config->buf[i] == NULL)
		{
			free_textures(config->buf, i);
			exit(0);
		}
		i++;
	}
	config->win = mlx_new_window(config->mlx, config->win_rows, \
	config->win_cols, "mlx_test");
	init_texture(config);
	load_textures(config);
}
