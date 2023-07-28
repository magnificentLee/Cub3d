/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:21:17 by sejokim           #+#    #+#             */
/*   Updated: 2023/07/28 20:24:55 by jeongmil         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mapping/mapping.h"

int	main(int ac, char **av)
{
	t_config	config;
	t_mlx		mlx;

	if (ac != 2)
	{
		printf("Usage: %s [config_file]\n", av[0]);
		return (1);
	}
	config.map_rows = 0;
	config.map_cols = 0;
	map_reading(av[1], &config);
	
//	printf("north_texture : %s\n", config.north_texture);
//	printf("south_texture : %s\n", config.south_texture);
//	printf("west_texture : %s\n", config.west_texture);
//	printf("east_texture : %s\n", config.east_texture);
//	printf("floor_color : %s\n", config.floor_color);
//	printf("ceiling_color : %s\n", config.ceiling_color);
	printf("map_rows : %d\n", config.map_rows);
	printf("map_cols : %d\n", config.map_cols);

	init_texture(&mlx);
	mlx.win = mlx_new_window(mlx.mlx, winRowSize, winColSize, "mlx_test");
	mapping(&config, &mlx);
	// rendering map function
	mlx_hook(mlx.win, X_EVENT_KEY_PRESS, 0, &key_press, &mlx);
	mlx_hook(mlx.win, WINDOW_EXIT, 0, &mouth_press, &mlx);
	mlx_loop(mlx.mlx);

	return (0);	
}
