/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:06:57 by jeongmil          #+#    #+#             */
/*   Updated: 2023/07/31 23:06:58 by jeongmil         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	setPlayerPosition(t_config *config)
{
	int	i;
	int	j;

	j = 0;
	while (j < config->map_cols)
	{
		i = 0;
		while (i < config->map_rows)
		{
			if (config->map[j][i] == 'N')
			{
				config->playerX = i;
				config->playerY = j;
			}
			i++;
		}
		j++;
	}
}

void	initialize(t_config *config, char **av)
{
	int	i;

	i = 0;
	config->mlx = mlx_init();
	config->map_rows = 0;
	config->map_cols = 0;
	map_reading(av[1], config); // parsing
	config->win_rows = TEX_WIDTH * config->map_rows;
	config->win_cols = TEX_HEIGH * config->map_cols;
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
	config->playerX = -1;
	config->playerY = -1;
	setPlayerPosition(config);
	config->win = mlx_new_window(config->mlx, config->win_rows, config->win_cols, "mlx_test");
}