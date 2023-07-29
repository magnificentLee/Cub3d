/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:34:50 by jeongmil          #+#    #+#             */
/*   Updated: 2023/07/29 21:17:04 by jeongmil         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	init_texture(t_config *config)
{
	int	i;

	config->textures = (int **)malloc(sizeof(int *) * NUMBER_OF_IMG);
	if (config->textures == NULL)
		return (-1);
	i = 0;
	while (i < NUMBER_OF_IMG)
	{
		config->textures[i] = (int *)malloc(sizeof(int) * \
		(TEXTURE_ROW_SIZE * TEXTURE_COL_SIZE));
		if (config->textures[i] == NULL)
			return (free_textures(config->textures, i));
		i++;
	}
	load_textures(config);
	return (0);
}
/*
void	load_textures(t_config *config)
{
	load_image(config, "./img/AnyConv.com__barrel.xpm", config->textures[0]); // config->north_texture
	load_image(config, "./img/AnyConv.com__colorstone.xpm", config->textures[1]); // config->south_texture
	load_image(config, "./img/AnyConv.com__redbrick.xpm", config->textures[2]); // config->west_texture , test:wall
	load_image(config, "./img/AnyConv.com__greystone.xpm", config->textures[3]); // config->east_texture
	load_image(config, "./img/AnyConv.com__bluestone.xpm", config->textures[4]); // test, floor
}

void	load_image(t_config *config, char *img_file, int *texture)
{
	t_img	img;
	int		i;
	int		j;

	img.img = mlx_xpm_file_to_image(config->mlx, img_file, &img.img_row, &img.img_col); // 이미지 객체 생성
	img.img_data = (int *)mlx_get_data_addr(img.img, &img.bpp, &img.size_line, &img.endian); // 생성된 이미지 객체의 정보를 가져옴
	// image copy loop. check README.md -> mlx_get_data_addr
	j = 0;
	while (j < img.img_col)
	{
		i = 0;
		while (i < img.img_row)
		{
			texture[i + (img.img_row * j)] = img.img_data[i + (img.img_row * j)];
			i++;
		}
		j++;
	}
	mlx_destroy_image(config->mlx, img.img);
}
*/
int	free_textures(int **integer, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(integer[i]);
		i++;
	}
	free(integer);
	return (-1);
}

void	load_textures(t_config *config)
{
	t_img	img;
	
	load_image(config, "./img/AnyConv.com__barrel.xpm", config->textures[0], &img); // config->north_texture
	load_image(config, "./img/AnyConv.com__colorstone.xpm", config->textures[1], &img); // config->south_texture
	load_image(config, "./img/AnyConv.com__redbrick.xpm", config->textures[2], &img); // config->west_texture , test:wall
	load_image(config, "./img/AnyConv.com__greystone.xpm", config->textures[3], &img); // config->east_texture
	load_image(config, "./img/AnyConv.com__bluestone.xpm", config->textures[4], &img); // test, floor
}

void	load_image(t_config *config, char *img_file, int *texture, t_img *img)
{
	int		i;
	int		j;

	img->img = mlx_xpm_file_to_image(config->mlx, img_file, &img->img_row, &img->img_col); // 이미지 객체 생성
	img->img_data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_line, &img->endian); // 생성된 이미지 객체의 정보를 가져옴
	// image copy loop. check README.md -> mlx_get_data_addr
	j = 0;
	while (j < img->img_col)
	{
		i = 0;
		while (i < img->img_row)
		{
			texture[i + (img->img_row * j)] = img->img_data[i + (img->img_row * j)];
			i++;
		}
		j++;
	}
	mlx_destroy_image(config->mlx, img->img);
}
