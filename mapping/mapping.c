/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:38:46 by jeongmil          #+#    #+#             */
/*   Updated: 2023/07/31 23:04:43 by jeongmil         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_map(t_config *config)
{
	int	i;
	int	j;

	j = 0;
	while (j < config->win_cols)
	{
		i = 0;
		while (i < config->win_rows)
		{
			config->img.data[config->win_rows * j + i] = config->buf[j][i];
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(config->mlx, config->win, config->img.img, 0, 0);
}

int	*find_texture(t_config *config, int x, int y)
{
	if (config->map[y][x] == '0')
		return (config->textures[4]);
	else if (config->map[y][x] == '1' || config->map[y][x] == '2')
		return (config->textures[2]);
	else if (config->map[y][x] == 'N')
		return (config->textures[0]);
	else
		return (config->textures[3]);
}

void	fill_square(t_config *config, int *img_texture, int x, int y)
{ 	// 타일의 크기 결정
	int	i;
	int	j;

	j = 0;
	while (j < TEX_HEIGH)
	{
		i = 0;
		while (i < TEX_WIDTH)
		{
			config->buf[j + y][i + x] = img_texture[TEX_WIDTH * j + i];
			i++;
		}
		j++;
	}
}

void	mapping(t_config *config)
{	// 화면에 찍히는 위치 결정, 전체적인 맵의 크기가 커짐
	int	i;
	int	j;
	int	*img_texture;

	j = 0;
	while (j < config->map_cols)
	{
		i = 0;
		while (i < config->map_rows)
		{
			img_texture = find_texture(config, i, j);
			fill_square(config, img_texture, i * TEX_WIDTH, j * TEX_HEIGH);
			i++;
		}
		j++;
	}
}
