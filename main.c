/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:21:17 by sejokim           #+#    #+#             */
/*   Updated: 2023/08/03 15:36:14 by jeongmil         ###   ########seoul.kr  */
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

int	main(int ac, char **av)
{
	t_config	*config;

	config = malloc(sizeof(t_config));
	if (!config)
		parse_error("malloc failed.\n", 2);
	if (check_not_valid(ac, av, config))
		return (1);
	initialize(config, av);
	// 출력용
	config->img.img = mlx_new_image(config->mlx, config->win_rows, config->win_cols);
	config->img.data = (int *)mlx_get_data_addr(config->img.img, &config->img.bpp, &config->img.size_l, &config->img.endian);
	mapping(config);
	draw_map(config);

	mlx_hook(config->win, X_EVENT_KEY_PRESS, 0, &key_press, config);
	mlx_hook(config->win, WINDOW_EXIT, 0, &mouth_press, config);
	mlx_loop(config->mlx);
	free(config);
}