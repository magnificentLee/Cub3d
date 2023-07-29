/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:38:46 by jeongmil          #+#    #+#             */
/*   Updated: 2023/07/29 22:36:16 by jeongmil         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

void	mapping_square(t_config *config, int x, int y);

void	mapping(t_config *config)
{
	int	i;
	int	j;

	j = 0;
	while (j < config->map_cols)
	{
		i = 0;
		while (i < config->map_rows)
		{
			if (config->map[j][i] == '1')
				put_image_to_window()
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(config->mlx, config->win, config->img.img, (int)(MINISCALE * WIN_ROW_SIZE) *(1 - MINISCALE), (int)(MINISCALE * WIN_COL_SIZE) *(1 - MINISCALE));
}

void	put_image_to_window_empty(t_config *config, char sep, int i, int j)
{
	int	k;

	if (sep == '\t')
	{
		k = 0;
		while (k < 4)
		{
			mlx_put_image_to_window(config->mlx, config->win, config->textures[3], \
			(i + k) * TEXTURE_ROW_SIZE
			, j * TEXTURE_COL_SIZE);
			k++;
		}
	}
	else
		mlx_put_image_to_window(config->mlx, config->win, config->textures[3], \
		i * TEXTURE_ROW_SIZE, j * TEXTURE_COL_SIZE);
}

void	put_image_to_window(t_config *config, int *texture, int i, int j)
{
	mlx_put_image_to_window(config->mlx, config->win, img, \
	i * TEXTURE_ROW_SIZE, j * TEXTURE_COL_SIZE);
}
/*
void	put_player_to_window(t_mlx *mlx, int i, int j)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, )	
	}
	
	for (int idx = 0; idx < 50; idx++) {
		mlx_pixel_put(mlx->mlx, mlx->win, (i + idx) * tileSize, j * tileSize, 0xFF0000); // red
	}
//	mlx_pixel_put(mlx->mlx, mlx->win, i * tileSize, j * tileSize, 0x0000FF);
}
*/
