/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:38:46 by jeongmil          #+#    #+#             */
/*   Updated: 2023/07/30 21:53:47 by jeongmil         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_map(t_config *config)
{
	int	i;
	int	j;

	j = 0;
	while (j < WIN_HEIGH)
	{
		i = 0;
		while (i < WIN_WIDTH)
		{
			config->img.data[j * WIN_WIDTH + i] = config->buf[j][i];
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(config->mlx, config->win, config->img.img, 0, 0);
}

void	fill_square(t_config *config, int pixel, int x, int y)
{ 	// 타일의 크기 결정
	int	i;
	int	j;

	j = y;
	while (j < y + 64)
	{
		i = x;
		while (i < x + 64)
		{
			config->buf[j][i] = pixel;
			i++;
		}
		j++;
	}
}

void	mapping(t_config *config)
{	// 화면에 찍히는 위치 결정, 전체적인 맵의 크기가 커짐
	int	i;
	int	j;
	int	x;
	int	y;
	int	pixel;

	j = 0;
	y = 0;
	while (j < config->map_cols)
	{
		i = 0;
		x = 0;
		while (i < config->map_rows)
		{
			if (config->map[j][i] == '0')
				pixel = config->textures[4][TEX_WIDTH * j + i];
			else if (config->map[j][i] == '1' || config->map[j][i] == '2')
				pixel = config->textures[2][TEX_WIDTH * j + i];
			else if (config->map[j][i] == 'N')
				pixel = config->textures[0][TEX_WIDTH * j + i];
			else
				pixel = config->textures[3][TEX_WIDTH * j + i];
//			config->buf[y][x] = pixel;
			fill_square(config, pixel, x, y);
			i++;
			x += 32;
		}
		j++;
		y += 32;
	}
	draw_map(config);
}
