/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:21:17 by sejokim           #+#    #+#             */
/*   Updated: 2023/07/29 21:33:37 by jeongmil         ###   ########seoul.kr  */
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
	config.mlx = mlx_init();
	config.map_rows = 0;
	config.map_cols = 0;
	map_reading(av[1], &config); // parsing
	printf("map_rows : %d\n", config.map_rows);
	printf("map_cols : %d\n", config.map_cols);
	if (init_texture(&config) == -1)
		exit(0);
	// rendering map function
	config.win = mlx_new_window(config.mlx, WIN_ROW_SIZE, WIN_COL_SIZE, "mlx_test");
	config.img.img = mlx_new_image(config.mlx, MINISCALE * WIN_ROW_SIZE, MINISCALE * WIN_COL_SIZE);
	mapping(&config);
	mlx_hook(config.win, X_EVENT_KEY_PRESS, 0, &key_press, &config);
	mlx_hook(config.win, WINDOW_EXIT, 0, &mouth_press, &config);
	mlx_loop(config.mlx);

	return (0);	
}
