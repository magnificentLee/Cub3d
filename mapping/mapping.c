/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:38:46 by jeongmil          #+#    #+#             */
/*   Updated: 2023/08/03 15:42:58 by jeongmil         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "mapping.h"

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
	// 맵이 사각형이 아닌 경우, 벽을 넘어서 NULL일 부분에 접근해서 맵을 생성하는데 어떻게 막아야 될지 모르겠음
	if (config->map[y][x] == '0')
		return (config->textures[4]);
	else if (config->map[y][x] == '1')
		return (config->textures[2]);
	else if (config->map[y][x] == 'N') // need S E W
		return (config->textures[0]);
	else
		return (config->textures[3]);
}

void	fill_square(t_config *config, int *img_texture, int x, int y)
{ 	// 타일의 크기 결정, 축소 타일이 아닌 타일의 size/n 꼴로 출력됨, TEX_HEIGH/SIZEVALUE = 32, 64*64*1/4 = 32*32 이므로 타일의 1/4 부분만 출력됨
	int	i;
	int	j;

	j = 0;
	while (j < TEX_HEIGH / SIZEVALUE)
	{
		i = 0;
		while (i < TEX_WIDTH / SIZEVALUE)
		{
			config->buf[y + j][x + i] = img_texture[TEX_WIDTH * j + i];
			i++;
		}
		j++;
	}
}

void	mapping(t_config *config)
{	// 화면에 찍히는 위치 결정, 전체적인 맵의 크기가 커짐, 작은 맵을 원하면 fill_square 인자로 들어가는 x, y 값을 줄일 것
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
			fill_square(config, img_texture, i * TEX_WIDTH / SIZEVALUE, j * TEX_HEIGH / SIZEVALUE);
			i++;
		}
		j++;
	}
}
