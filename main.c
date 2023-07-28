/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:21:17 by sejokim           #+#    #+#             */
/*   Updated: 2023/07/26 18:47:24 by sejokim          ###   ########.fr       */
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
	config = parse_config(av[1]);
	printf("north_texture : %s\n", config.north_texture);
	printf("south_texture : %s\n", config.south_texture);
	printf("west_texture : %s\n", config.west_texture);
	printf("east_texture : %s\n", config.east_texture);
	printf("floor_color : %s\n", config.floor_color);
	printf("ceiling_color : %s\n", config.ceiling_color);
	printf("map_rows : %d\n", config.map_rows);
	printf("map_cols : %d\n", config.map_cols);
}
