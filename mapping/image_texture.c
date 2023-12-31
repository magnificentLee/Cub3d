/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:34:50 by jeongmil          #+#    #+#             */
/*   Updated: 2023/08/03 20:38:12 by jeongmil         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "mapping.h"

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
		(TEX_WIDTH * TEX_HEIGH));
		if (config->textures[i] == NULL)
			return (free_textures(config->textures, i));
		i++;
	}
	return (0);
}

void	load_textures(t_config *config)
{
	// config->no_tex;
	load_image(config, config->no_tex, config->textures[0]); // config->north_texture
	load_image(config, config->so_tex, config->textures[1]); // config->south_texture
	load_image(config, "img/AnyConv.com__redbrick.xpm", config->textures[2]); // config->west_texture , test:wall
	load_image(config, "img/AnyConv.com__colorstone.xpm", config->textures[3]); // config->east_texture
	load_image(config, "img/AnyConv.com__bluestone.xpm", config->textures[4]); // test, floor,, delete
}

void	load_image(t_config *config, char *img_file, int *texture)
{
	t_img	img;
	int		i;
	int		j;

	img.img = mlx_xpm_file_to_image(config->mlx, img_file, \
	&img.img_width, &img.img_height);
	img.data = (int *)mlx_get_data_addr(img.img, &img.bpp, \
	&img.size_l, &img.endian);
	j = 0;
	while (j < img.img_height)
	{
		i = 0;
		while (i < img.img_width)
		{
			texture[img.img_width * j + i] = img.data[img.img_width * j + i];
			i++;
		}
		j++;
	}
	mlx_destroy_image(config->mlx, img.img);
}

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
