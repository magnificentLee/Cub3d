/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:21:17 by sejokim           #+#    #+#             */
/*   Updated: 2023/07/31 20:06:07 by jeongmil         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_config	config;

	if (ac != 2)
	{
		printf("Usage: %s [config_file]\n", av[0]);
		return (1);
	}

	initialize(&config, av);
	printf("map_rows : %d\n", config.map_rows);
	printf("map_cols : %d\n", config.map_cols);
	init_texture(&config);
	load_textures(&config);
	// rendering map function
	config.img.img = mlx_new_image(config.mlx, config.win_rows, config.win_cols);
	config.img.data = (int *)mlx_get_data_addr(config.img.img, &config.img.bpp, &config.img.size_l, &config.img.endian);

	mapping(&config);
	draw_map(&config);

	mlx_hook(config.win, X_EVENT_KEY_PRESS, 0, &key_press, &config);
	mlx_hook(config.win, WINDOW_EXIT, 0, &mouth_press, &config);
	mlx_loop(config.mlx);

	return (0);	
}
