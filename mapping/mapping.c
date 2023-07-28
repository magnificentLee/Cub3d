/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:38:46 by jeongmil          #+#    #+#             */
/*   Updated: 2023/07/28 21:57:07 by jeongmil         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"
#include "mapping.h"

void	init_texture(t_mlx *mlx)
{
	mlx->win_row = winRowSize; // 가변적이게 수정 예정
	mlx->win_col = winColSize; // 가변적이게 수정 예정
	mlx->mlx = mlx_init();
	mlx->img_north = mlx_xpm_file_to_image(mlx->mlx, "./img/AnyConv.com__barrel.xpm", &mlx->win_row, &mlx->win_col);
	mlx->img_floor = mlx_xpm_file_to_image(mlx->mlx, "./img/AnyConv.com__colorstone.xpm", &mlx->win_row, &mlx->win_col);
//	mlx->img_wall = mlx_xpm_file_to_image(mlx->mlx, "./img/AnyConv.com__redbrick.xpm", &mlx->win_row, &mlx->win_col);
	mlx->img_wall = mlx_xpm_file_to_image(mlx->mlx, "./img/AnyConv.com__bluestone.xpm", &mlx->win_row, &mlx->win_col); // 테스트용
	mlx->img_empty = mlx_xpm_file_to_image(mlx->mlx, "./img/AnyConv.com__bluestone.xpm", &mlx->win_row, &mlx->win_col);
	
}

void	mapping(t_config *config, t_mlx *mlx)
{
	int	i;
	int	j;

	j = 0;
	while (j < config->map_rows)
	{
		i = 0;
		while (i < config->map_cols)
		{
			if (config->map[j][i] == '0')
				put_image_to_window(mlx, mlx->img_floor, i, j); // tmp floor texture
			else if (config->map[j][i] == 'N')
			{
				// 플레이어 위치를 찍기 위한 테스트 코드
				put_image_to_window(mlx, mlx->img_north, i, j);
				put_player_to_window(mlx, i, j);				
			}
			else if (config->map[j][i] == '1' || config->map[j][i] == '2')
				put_image_to_window(mlx, mlx->img_wall, i, j); // tmp wall texture
			else
				put_image_to_window_empty(mlx, config->map[j][i], i, j);
			i++;
		}
		j++;
	}
}

void	put_image_to_window_empty(t_mlx *mlx, char sep, int i, int j)
{
	int	k;

	if (sep == '\t')
	{
		k = 0;
		while (k < 4)
		{
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_empty, (i + k) * tileSize, j * tileSize);
			k++;
		}
	}
	else
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_empty, i * tileSize, j * tileSize);
}

void	put_image_to_window(t_mlx *mlx, void *img_file, int i, int j)
{
	// if문은 플레이어 밑을 바닥으로 덧칠하기 위한 코드, 필요 없을 수도 있음
	if (img_file == mlx->img_north)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_floor, i * tileSize, j * tileSize);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img_file, i * tileSize, j * tileSize);
}

void	put_player_to_window(t_mlx *mlx, int i, int j)
{
	/*
	int	i;

	i = 0;
	while (i < 8)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, )	
	}
	*/
	for (int idx = 0; idx < 50; idx++) {
		mlx_pixel_put(mlx->mlx, mlx->win, (i + idx) * tileSize, j * tileSize, 0xFF0000); // red
	}
//	mlx_pixel_put(mlx->mlx, mlx->win, i * tileSize, j * tileSize, 0x0000FF);
}
