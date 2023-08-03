/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:21:17 by sejokim           #+#    #+#             */
/*   Updated: 2023/08/03 19:56:49 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_not_valid(int ac, char **av, t_config *config)
{
	if (ac != 2)
	{
		printf("Usage: %s [config_file]\n", av[0]);
		free(config);
		return (1);
	}
	return (0);
}

// void	print_map(t_config *config)
// {
// 	int	col;

// 	col = 0;
// 	while (col < config->map_cols)
// 	{
// 		printf("%s", config->map[col]);
// 		col++;
// 	}
// }

int	main(int ac, char **av)
{
	t_config	*config;

	config = malloc(sizeof(t_config));
	if (!config)
		parse_error("malloc failed.\n", 2);
	if (check_not_valid(ac, av, config))
		return (1);
	initialize(config, av);
	config->img.img = mlx_new_image(config->mlx, \
	config->win_rows, config->win_cols);
	config->img.data = (int *)mlx_get_data_addr(config->img.img, \
	&config->img.bpp, &config->img.size_l, &config->img.endian);
	mapping(config);
	draw_map(config);
	mlx_hook(config->win, X_EVENT_KEY_PRESS, 0, &key_press, config);
	mlx_hook(config->win, WINDOW_EXIT, 0, &mouth_press, config);
	mlx_loop(config->mlx);

	// printf("map_rows: %f\n", config->r_pos.posX);
	// printf("map_cols: %f\n", config->r_pos.posY);
	// printf("map_rows: %d\n", config->map_rows);
	// printf("map_cols: %d\n", config->map_cols);
	// printf("notex : %s\n", config->no_tex);
	// printf("sotex : %s\n", config->so_tex);
	// printf("wetex : %s\n", config->we_tex);
	// printf("eatex : %s\n", config->ea_tex);
	// printf("floor color : %d\n", config->floor_color);
	// printf("ceiling color : %d\n", config->ceiling_color);
	// print_map(config);
	free(config);
}
